cmake_minimum_required(VERSION 3.14)
project("Project Euler" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_library(common common.cpp common.h)
target_compile_features(common PUBLIC cxx_std_17)
target_compile_options(common PRIVATE -Wall -Wextra -Wmost -pedantic -Wconversion -Wfloat-equal -Wold-style-cast)
target_include_directories(common PRIVATE "/Users/toxe/suite/build/include")
set_target_properties(common PROPERTIES CXX_EXTENSIONS OFF)

set(ALL_TARGETS
    euler001
    euler002
    euler003
    euler004
    euler005
    euler006
    euler007
    euler008
    euler009
    euler010
    euler011
    euler012
    euler013
    euler014
    euler015
    euler016
    euler017
    euler018
    euler067
)

foreach(target ${ALL_TARGETS})
    add_executable(${target} ${target}.cpp)
    target_compile_features(${target} PUBLIC cxx_std_17)
    target_compile_options(${target} PRIVATE -Wall -Wextra -Wmost -pedantic -Wconversion -Wfloat-equal -Wold-style-cast)
    target_include_directories(${target} PRIVATE "/Users/toxe/suite/build/include")
    set_target_properties(${target} PROPERTIES CXX_EXTENSIONS OFF)
endforeach()

target_link_libraries(euler007 PRIVATE common)
target_link_libraries(euler010 PRIVATE common)
