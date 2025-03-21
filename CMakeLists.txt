cmake_minimum_required (VERSION 3.10)
project(cpp-googletest)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(memento_bank SHARED src/memento_bank.cpp)
target_include_directories(memento_bank PUBLIC include)

# Add GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        main
)
FetchContent_MakeAvailable(googletest)
enable_testing()

add_subdirectory(tests)
