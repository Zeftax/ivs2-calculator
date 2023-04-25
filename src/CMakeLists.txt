###################################################
# Application name: ratulator
# Project: ivs2-calculator
#
# Date:         2023-04-10
# File:         CMakeLists.txt
#
# Author: Zdeněk Borovec <xborov08@vutbr.cz>
# Author: Tomáš Krejčí   <xkrejc84@vutbr.cz>
# Author: Jan Lozrt      <xlozrt00@vutbr.cz>
# Author: Jakub Mitrenga <xmitre07@vutbr.cz>
#
# Description: Simple calculator app
#
###################################################

# == SETUP ==
cmake_minimum_required(VERSION 3.16)
project("ratulator"
        VERSION 0.1.0
        DESCRIPTION "Simple calculator app"
)

# find math library
add_subdirectory("extern/ivs2-mathlib")

include_directories(inc)
include_directories(src)

set(CMAKE_CXX_STANDARD 17)

# -- create gresource file --
find_program(GLIB_COMPILE_RESOURCES NAMES glib-compile-resources REQUIRED)

set(GRESOURCE_C resources.cpp)
set(GRESOURCE_XML res/resources.xml)

add_custom_command(
    OUTPUT ${GRESOURCE_C}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${GLIB_COMPILE_RESOURCES}
    ARGS
        --generate-source
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
        ${GRESOURCE_XML}
    VERBATIM
    MAIN_DEPENDENCY ${GRESOURCE_XML}
    DEPENDS
        res/ratulator.glade
)

add_custom_target(
    resources
    DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

# -- link sources --
add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/calculator.cpp
        src/rootNode.cpp
        ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
)

set_source_files_properties(
    ${CMAKE_CURRENT_BINARY_DIR}/${GRESOURCE_C}
    PROPERTIES GENERATED TRUE
)

add_dependencies(${PROJECT_NAME} resources)

# link math library
target_link_libraries(${PROJECT_NAME} PRIVATE ivs2-mathlib)


# -- GTK 4 setup --
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED IMPORTED_TARGET gtkmm-3.0)

target_link_libraries(${PROJECT_NAME} PRIVATE PkgConfig::gtkmm)

# -- include cmake scripts --
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Install)
include(Package)

# -- doxygen target --
find_package(Doxygen 1.8.0)
if(DOXYGEN_FOUND)
    set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)
    add_custom_target(doc
            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
            WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM
            )
endif()
