cmake_minimum_required(VERSION 3.22)
project(COLA_min_example VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

# Find needed module package
find_package(ExModule)

add_executable(COLA_min_example main.cpp)

target_include_directories(COLA_min_example PRIVATE ${COLA_DIR}/include)
target_link_libraries(COLA_min_example PRIVATE ExModule)