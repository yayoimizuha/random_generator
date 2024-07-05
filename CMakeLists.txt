cmake_minimum_required(VERSION 3.29)
project(random_generator)


find_package(OpenMP REQUIRED)
if(OpenMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

set(CMAKE_CXX_STANDARD 20)

add_executable(uniform_random uniform_random.cpp)
add_executable(many_overlaps many_overlaps.cpp)
add_executable(almost_same almost_same.cpp)
add_executable(forward_order forward_order.cpp)
add_executable(backward_order backward_order.cpp)
