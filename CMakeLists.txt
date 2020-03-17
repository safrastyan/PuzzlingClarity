cmake_minimum_required (VERSION 2.8)
project(PuzzlingClarity)
SET(CMAKE_BUILD_TYPE Release)
SET(CMAKE_CXX_COMPILER /usr/bin/g++)
add_definitions(-std=c++14 -O0 -g)
include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

find_package(Boost 1.50.0 COMPONENTS unit_test_framework filesystem system REQUIRED)

add_definitions(-DBOOST_TEST_DYN_LINK)
add_library(PuzzlingClarity ${SRCS})
target_link_libraries(PuzzlingClarity ${Boost_LIBRARIES})

# Executables
file(GLOB_RECURSE EXECS ${PROJECT_SOURCE_DIR}/main/*.cpp)

FOREACH(exec_src ${EXECS})
    STRING(REPLACE "${PROJECT_SOURCE_DIR}/" "" exec_loc ${exec_src})
    get_filename_component(exec_name ${exec_src} NAME_WE)
    STRING(REPLACE "/${exec_name}.cpp" "" exec_loc ${exec_loc})
    SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${exec_loc}")
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
    add_executable(${exec_name} ${exec_src})
    target_link_libraries(${exec_name} PuzzlingClarity)
ENDFOREACH()

# Tests

file(GLOB_RECURSE TESTS ${PROJECT_SOURCE_DIR}/tests/*.cpp)


FOREACH(exec_src ${TESTS})
    STRING(REPLACE "${PROJECT_SOURCE_DIR}/" "" exec_loc ${exec_src})
    get_filename_component(exec_name ${exec_src} NAME_WE)
    STRING(REPLACE "/${exec_name}.cpp" "" exec_loc ${exec_loc})
    SET(EXECUTABLE_OUTPUT_PATH "${CMAKE_BINARY_DIR}/${exec_loc}")
    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXECUTABLE_OUTPUT_PATH})
    add_executable(${exec_name} ${exec_src})
    target_link_libraries(${exec_name} PuzzlingClarity ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
ENDFOREACH()
