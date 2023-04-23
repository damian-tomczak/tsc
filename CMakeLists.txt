cmake_minimum_required(VERSION 3.10)

if(NOT MSVC AND NOT WIN32)
    message(WARNING "Config with MSVC and WIN32 was only tested!")
endif()

set(QT_PATH CACHE STRING "QT path e.g. F:/qt/5.15.2/msvc2019_64")
if("${QT_PATH}" STREQUAL "")
    message(FATAL_ERROR "You need to first define QT_PATH")
endif()
list(APPEND CMAKE_PREFIX_PATH ${QT_PATH})

project(tsc VERSION 0.0.1 LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Qt5 REQUIRED COMPONENTS
    Core
    Widgets
    OpenGL
    SerialPort
)

add_subdirectory(src)