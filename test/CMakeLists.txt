cmake_minimum_required(VERSION 3.22)
project(COLA_min_example VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

# Find COLA package
find_package(COLAlib)

# Find neede module package
find_package(ExModule)

add_executable(COLA_min_example main.cpp)

target_link_libraries(COLA_min_example PRIVATE ExModule)