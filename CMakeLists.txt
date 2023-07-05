cmake_minimum_required(VERSION 3.22)
project(COLA_min_example)

set(CMAKE_CXX_STANDARD 14)

find_package(COLA)

add_executable(COLA_min_example main.cpp)

target_link_libraries(COLA_min_example PRIVATE COLAlib)

