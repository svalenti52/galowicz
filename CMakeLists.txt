cmake_minimum_required(VERSION 3.15)
project(Galowicz)

set(CMAKE_CXX_STANDARD 17)

add_executable(Parallel parallel.cpp)
add_executable(Parallel_naive parallel_naive.cpp)
