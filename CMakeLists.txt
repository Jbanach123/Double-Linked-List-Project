cmake_minimum_required(VERSION 3.10)
project(Project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(ProjectExecutable src/main.cpp)
target_include_directories(ProjectExecutable PUBLIC include)
