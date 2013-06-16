cmake_minimum_required(VERSION 2.8)
CMAKE_POLICY(SET CMP0017 NEW)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/Modules")

if(NOT TOMAHAWK_LIBRARIES)
    message(STATUS "BUILDING OUTSIDE TOMAHAWK")
    find_package(Tomahawk REQUIRED)
else()
    message(STATUS "BUILDING INSIDE TOMAHAWK")
    set(TOMAHAWK_USE_FILE "${CMAKE_SOURCE_DIR}/TomahawkUse.cmake")
endif()
include( ${TOMAHAWK_USE_FILE} )

include_directories( ${TOMAHAWK_INCLUDE_DIRS} )

tomahawk_add_plugin( stub
    TYPE infoplugin
    EXPORT_MACRO INFOPLUGINDLLEXPORT_PRO
    SOURCES
        PluginStub.cpp
    LINK_LIBRARIES
        ${TOMAHAWK_LIBRARIES}
)
