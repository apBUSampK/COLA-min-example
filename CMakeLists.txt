cmake_minimum_required(VERSION 3.22)
project(COLA_min_example)

set(CMAKE_CXX_STANDARD 14)

find_package(COLA)

add_executable(COLA_min_example main.cpp)

target_include_directories(COLA_min_example PUBLIC ${COLA_INCLUDE_DIR})