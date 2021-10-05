cmake_minimum_required(VERSION 3.20)
project(cp-roadmap-checklist)

ADD_DEFINITIONS(-std=c++17)

add_executable(generate_md_file generate_md_file.cpp)
#target_link_libraries(generate_md_file csv.hpp)