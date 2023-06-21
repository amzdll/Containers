set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.21)
project(containers LANGUAGES CXX)

enable_testing()
find_package(GTest REQUIRED)

include_directories(src)
include_directories(src/list)
include_directories(src/queue)
include_directories(src/stack)
include_directories(src/vector)
include_directories(src/map)
include_directories(src/set)

add_executable(
        list
        src/list/s21_list.cpp
        src/list/s21_list.h
        src/list/s21_list_test.cpp)

add_executable(
        queue
        src/queue/s21_queue.cpp
        src/queue/s21_queue.h
        src/queue/s21_queue_test.cpp)

add_executable(
        stack
        src/stack/s21_stack.cpp
        src/stack/s21_stack.h
        src/stack/s21_stack_test.cpp)

add_executable(
        vector
        src/vector/s21_vector.cpp
        src/vector/s21_vector.h
        src/vector/s21_vector_test.cpp
        src/vector/s21_vector.cpp)

add_executable(
        map
        src/map/s21_map.cpp
        src/map/s21_map.h
        src/map/s21_map_test.cpp)

add_executable(
        tree
        src/tree
        src/tree/tree.cpp
        src/tree/tree.h)


add_executable(
        tests
        src/map/test.cpp
        src/map/test.h
        src/map/test_methods.cpp)

target_link_libraries(list gtest pthread)
target_link_libraries(queue gtest pthread)
target_link_libraries(stack gtest pthread)
target_link_libraries(vector gtest pthread)
target_link_libraries(map gtest pthread)

