cmake_minimum_required(VERSION 3.8)
project(Project4)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror=return-type")

add_executable(main main.cpp)