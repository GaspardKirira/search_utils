cmake_minimum_required(VERSION 3.20)
project(search_utils LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(search_utils INTERFACE)
add_library(search_utils::search_utils ALIAS search_utils)

target_include_directories(search_utils INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

if (MSVC)
  target_compile_options(search_utils INTERFACE /W4 /permissive-)
else()
  target_compile_options(search_utils INTERFACE -Wall -Wextra -Wpedantic)
endif()

include(CTest)
enable_testing()

add_executable(search_utils_basic_test tests/test_basic.cpp)
target_link_libraries(search_utils_basic_test PRIVATE search_utils::search_utils)
add_test(NAME search_utils.basic COMMAND search_utils_basic_test)
