###################################################
# Project name: ivs2-calculator
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
project("ivs2-calculator"
        VERSION 0.1.0
        DESCRIPTION "Simple calculator app"
)

# find math library
set(CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/extern/ivs2-mathlib/install")
find_package(ivs2-mathlib 0.1 CONFIG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
        src/calculator.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE ivsm::ivs2-mathlib)

