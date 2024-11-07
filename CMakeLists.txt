cmake_minimum_required(VERSION 3.16.0)
project(cpphub_templates)
set(CMAKE_CXX_STANDARD 11)

add_executable(using_templates using_templates.cpp)
add_executable(creating_templates creating_templates.cpp)
add_executable(variadic_templates variadic_templates.cpp)

add_subdirectory(cpp20)
