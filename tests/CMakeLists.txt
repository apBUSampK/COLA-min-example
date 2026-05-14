#
# Copyright (c) 2024-2025 Alexandr Svetlichnyi, Savva Savenkov, Artemii Novikov
#
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
# associated documentation files (the "Software"), to deal in the Software without restriction,
# including without limitation the rights to use, copy, modify, merge, publish, distribute,
# sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all copies or
# substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
# NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
# DAMAGES OR OTHER* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

# Tests (GoogleTest)
find_package(GTest REQUIRED)

# Include CMake module for gtest_discover_tests
include(GoogleTest)

# Add test executable
add_executable(ExModuleTest exmodule_test.cc)

set_target_properties(
    ExModuleTest
    PROPERTIES CXX_STANDARD 20
               CXX_STANDARD_REQUIRED YES
               CXX_EXTENSIONS NO
               CXX_CLANG_TIDY "${COLA_CMAKE_CXX_CLANG_TIDY}"
)

# Link against ExModule and GTest
target_link_libraries(ExModuleTest ExModule)
target_link_libraries(ExModuleTest GTest::GTest GTest::Main)

gtest_discover_tests(ExModuleTest)
