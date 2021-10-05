cmake_minimum_required(VERSION 3.20)
project(cp-roadmap-checklist)

ADD_DEFINITIONS(-std=c++17)

add_executable(generate_md_file generate_md_file.cpp)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(generate_md_file PRIVATE Threads::Threads)

#target_link_libraries(generate_md_file csv.hpp)