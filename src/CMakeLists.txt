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

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/calculator.cpp
)

# link math library
target_link_libraries(${PROJECT_NAME} PRIVATE ivs2-mathlib)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(Install)

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

