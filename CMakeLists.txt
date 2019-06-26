cmake_minimum_required(VERSION 3.14)
project("Project Euler" LANGUAGES CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories("$ENV{SUITE_BUILD}/include")

add_executable(euler001 euler001.cpp)
add_executable(euler002 euler002.cpp)

target_compile_features(euler001 PUBLIC cxx_std_17)
target_compile_features(euler002 PUBLIC cxx_std_17)

set_target_properties(euler001 PROPERTIES CXX_EXTENSIONS OFF)
set_target_properties(euler002 PROPERTIES CXX_EXTENSIONS OFF)
