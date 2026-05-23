cmake_minimum_required(VERSION 3.14)

project(
    COLA_ExModule
    VERSION 1.1.0
    LANGUAGES CXX
)

set(COLA_MODULE_NAME ExModule)

# Find COLA package
find_package(COLA REQUIRED)

# Include CMake module for config file generation
include(CMakePackageConfigHelpers)
# GNUInstallDirs defines CMAKE_INSTALL_LIBDIR, INCLUDEDIR, DATAROOTDIR, etc. (lib vs lib64, share, ...).
include(GNUInstallDirs)

# Modules can be installed whenever you please, however grouping them all in COLA directory is neat and
# makes further adjustments to CMAKE_PREFIX_PATH unnecessary. It is also advised to put module files to corresponding
# directories to avoid pollution.
set(CMAKE_INSTALL_PREFIX ${COLA_DIR})

# GNUInstallDirs defines CMAKE_INSTALL_LIBDIR, INCLUDEDIR, DATAROOTDIR, etc. (lib vs lib64, share, ...).
include(GNUInstallDirs)

# optional clang-tidy string
set(COLA_CMAKE_CXX_CLANG_TIDY
    ""
    CACHE STRING "Passed to CMAKE_CXX_CLANG_TIDY for ${COLA_MODULE_NAME} targets"
)

# Add library target
file(GLOB SRCS CONFIGURE_DEPENDS src/*.cc)
add_library(${COLA_MODULE_NAME} SHARED ${SRCS})

# allow c++20
target_compile_features(${COLA_MODULE_NAME} PRIVATE cxx_std_20)

target_include_directories(
    ${COLA_MODULE_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                               $<INSTALL_INTERFACE:include/${COLA_MODULE_NAME}>
)

# Link against COLA
target_link_libraries(${COLA_MODULE_NAME} PUBLIC COLA)

# Set public header and enable clang-tidy
set_target_properties(
    ${COLA_MODULE_NAME}
    PROPERTIES PUBLIC_HEADER "include/${COLA_MODULE_NAME}.hh"
               VERSION "${PROJECT_VERSION}"
               SOVERSION "${PROJECT_VERSION_MAJOR}"
               CXX_CLANG_TIDY "${COLA_CMAKE_CXX_CLANG_TIDY}"
               # cmake makes the dependencies paths baked into the library
               BUILD_WITH_INSTALL_RPATH TRUE
               INSTALL_RPATH_USE_LINK_PATH TRUE
)

# Install library
install(
    TARGETS ${COLA_MODULE_NAME}
    EXPORT ${COLA_MODULE_NAME}Export
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}/${COLA_MODULE_NAME}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${COLA_MODULE_NAME}
    INCLUDES
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${COLA_MODULE_NAME}
)

# Install includes
install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${COLA_MODULE_NAME}
    FILES_MATCHING
    PATTERN "*.hh"
)

# Configure config files
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/data/${COLA_MODULE_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${COLA_MODULE_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${COLA_MODULE_NAME}
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${COLA_MODULE_NAME}ConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)

# Install export file and config files
install(EXPORT ${COLA_MODULE_NAME}Export
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${COLA_MODULE_NAME}
)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/${COLA_MODULE_NAME}Config.cmake"
              "${CMAKE_CURRENT_BINARY_DIR}/${COLA_MODULE_NAME}ConfigVersion.cmake"
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${COLA_MODULE_NAME}
)

add_subdirectory(bin)

enable_testing()
if (BUILD_TESTING)
    add_subdirectory(tests)
endif ()

# format and tidy targets (exclude COLA from checks)
setup_cola_quality_tools(EXCLUDE_PATTERNS ".*/COLA/.*")
