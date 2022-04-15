import copy
import os.path
import xml.etree.ElementTree as ET
from xml.dom import minidom
import os
import subprocess
import sys
import shutil

# from bs4 import BeautifulSoup

tree = ET.parse('cmu_interfaces.xml')
root = tree.getroot()

save_dir = "include/Mazda/Dbus/XML"

include_dir = "include/Mazda/Dbus/"
cpp_dir = "src/Mazda/Dbus"
tmp_dir = "tmp"

try:
    os.makedirs(tmp_dir)
except:
    pass

for child in root[1:]:
    new_tree = ET.ElementTree(element=ET.Element('node'))
    new_root = new_tree.getroot()
    new_root.append(copy.deepcopy(child))
    library = child.attrib['name']
    with open(os.path.join(save_dir, child.attrib['name'] + ".xml"), "w", newline='') as out:
        xmlstr = minidom.parseString(ET.tostring(new_root))
        xmlstr.firstChild.setAttribute("cppname", child.attrib['name'] + "_object")
        xmltxt = xmlstr.toprettyxml(indent="   ", newl='\n')
        # soup = BeautifulSoup(xmltxt,  features = "xml")
        # xmlstr = os.linesep.join([s for s in xmlstr.splitlines() if s.strip()])
        # print(soup.prettify())
        out.write(xmltxt)
    try:
        os.makedirs(os.path.join(include_dir, child.attrib['name']))
    except FileExistsError:
        pass
    try:
        os.makedirs(os.path.join(cpp_dir, child.attrib['name']))
    except FileExistsError:
        pass
    subprocess.run(
        ["dbus-cxx-xml2cpp", "-x={}".format(os.path.join(os.getcwd(), save_dir, child.attrib['name'] + ".xml")),
         "--proxy", "--adapter", "-f"], cwd=tmp_dir)
    includes = []
    cpp = []
    for filename in os.listdir(tmp_dir):
        if (filename.split('.')[1] == "h"):
            includes.append(filename)
            shutil.move(os.path.join(tmp_dir, filename), os.path.join(include_dir, child.attrib['name'], filename))
        else:
            cpp.append(filename)
            shutil.move(os.path.join(tmp_dir, filename), os.path.join(cpp_dir, child.attrib['name'], filename))
    source_files = os.path.join(cpp_dir, child.attrib['name'])
    include_files = os.path.join(include_dir, child.attrib['name'])
    cmake_template = f'cmake_minimum_required(VERSION 3.5.1)\nproject({library} LANGUAGES CXX)\nfile(GLOB_RECURSE source_files *.cpp)\nadd_library({library} STATIC ${{source_files}})\ntarget_include_directories({library} PUBLIC ../../../../{include_files}/)\n'
    with open(os.path.join(cpp_dir, library, "CMakeLists.txt"), "w") as cmake_out:
        cmake_out.write(cmake_template)
    print(cmake_template)
    print(includes, cpp)

# print(child.tag, child.attrib)

shutil.rmtree(tmp_dir)
