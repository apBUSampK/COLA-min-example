file(CREATE_LINK "${CMAKE_CURRENT_SOURCE_DIR}/config.xml" "${CMAKE_BINARY_DIR}/config.xml" SYMBOLIC)

add_executable(cola_exmodule_example main.cpp)

target_compile_features(cola_exmodule_example PRIVATE cxx_std_17)
target_link_libraries(cola_exmodule_example PRIVATE ExModule)

target_compile_definitions(
    cola_exmodule_example PRIVATE "EXMODULE_DEFAULT_CONFIG=\"${CMAKE_BINARY_DIR}/config.xml\""
)
