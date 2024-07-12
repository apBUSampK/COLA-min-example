cmake_minimum_required(VERSION 3.22)
project(COLA_ExModule VERSION 1.1)

# c++17 is recommended
set(CMAKE_CXX_STANDARD 17)

# Find COLA package
find_package(COLA)

# Include CMake module for config file generation
include(CMakePackageConfigHelpers)

# Modules can be installed whenever you please, however grouping them all in COLA directory is neat and
# makes further adjustments to CMAKE_PREFIX_PATH unnecessary. It is also advised to put module files to corresponding
# directories to avoid pollution.
set(CMAKE_INSTALL_PREFIX ${COLA_DIR})
set(COLA_MODULE_NAME ExModule)

# Add library target
set(srcs src/ExFactories.cc src/ExFilters.cc)
add_library(ExModule SHARED ${srcs})

target_include_directories(ExModule PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/${COLA_MODULE_NAME}>)

# Set public header
set_target_properties(ExModule PROPERTIES PUBLIC_HEADER include/ExModule.hh)

# Link against COLA
target_link_libraries(ExModule PUBLIC COLA)

# Configure config files
configure_package_config_file(
        "${PROJECT_SOURCE_DIR}/data/ExModuleConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/ExModuleConfig.cmake"
        INSTALL_DESTINATION lib/cmake/${COLA_MODULE_NAME}
        #PATH_VARS, etc.
        )

write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/ExModuleConfigVersion.cmake
        COMPATIBILITY AnyNewerVersion)

# Install library
install(TARGETS ExModule
        EXPORT ExModuleExport
        LIBRARY DESTINATION lib/${COLA_MODULE_NAME}
        PUBLIC_HEADER DESTINATION include/${COLA_MODULE_NAME}
        INCLUDES DESTINATION include/${COLA_MODULE_NAME})

# Install includes
install(DIRECTORY include/
        DESTINATION include/${COLA_MODULE_NAME})

# Install export file and config files
install(EXPORT ExModuleExport
        DESTINATION lib/cmake/${COLA_MODULE_NAME})

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ExModuleConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/ExModuleConfigVersion.cmake"
        DESTINATION lib/cmake/${COLA_MODULE_NAME})

