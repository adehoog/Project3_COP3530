# Project3_COP3530

#GUI used: SFML 2.5.1 (https://www.sfml-dev.org/download/sfml/2.5.1/) with TGUI 0.9.1 (https://tgui.eu/download/)
#Comiplier MnGW (https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download)

Sites provide setup tutorials for visual studio.


**Clion setup guide:**

copy all files in the bin folder into cmake-build-debug file in Clion project.
CMakeLists.txt should look like the following:
_CMAKE FILE:_

cmake_minimum_required(VERSION 3.2)

project(tguiTest)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tguiTest main.cpp)

set(SFML_DIR ".../SFML-2.5.1/lib/cmake/SFML") //make sure to include the exact file location

set(TGUI_DIR ".../TGUI-0.9/lib/cmake/TGUI")

find_package(SFML REQUIRED COMPONENTS system window graphics network audio)

find_package(TGUI REQUIRED COMPONENTS backends loading renders widgets)

target_link_libraries(tguiTest PRIVATE tgui sfml-graphics)
