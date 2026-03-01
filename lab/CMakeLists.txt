cmake_minimum_required(VERSION 3.15)

set(ProjectName main)

project(${ProjectName} CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${ProjectName} lab2_3.cpp Student.cpp Student.hpp)

target_link_libraries(${ProjectName} PRIVATE university)