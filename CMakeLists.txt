####
# This sets up the build system for the 'new-fprime-rngLibrary' project, including
# components and deployments from project.cmake. In addition, it imports the core F Prime components.
####

cmake_minimum_required(VERSION 3.13)
project(new-fprime-rngLibrary C CXX)

###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/fprime/cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines

register_fprime_build_autocoder("${CMAKE_CURRENT_LIST_DIR}/fprime-subtopology-tool/src/cmake/autocoder/subtopology.cmake" ON) 

fprime_setup_included_code()


# This includes project-wide objects
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
