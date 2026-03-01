cmake_minimum_required(VERSION 3.15)

set(ProjectName university)

project(${ProjectName} CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

add_library(${ProjectName} STATIC university.cpp university.hpp)

target_include_directories(${ProjectName} PUBLIC .)