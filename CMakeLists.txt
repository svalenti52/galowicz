cmake_minimum_required(VERSION 3.15)
project(Galowicz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Parallel parallel.cpp)
add_executable(Parallel_naive parallel_naive.cpp)
add_executable(Mandelbrodt mandelbrodt.cpp)
add_executable(PROD_CSUM producer_consumer.cpp)
