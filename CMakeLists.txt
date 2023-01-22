cmake_minimum_required(VERSION 3.21)
project(containers)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/list)
include_directories(src/queue)
include_directories(src/stack)
include_directories(src/vector)
include_directories(src/map)
include_directories(src/set)

include(GoogleTest)

add_executable(
        list
        src/list/s21_list.cpp
        src/list/s21_list.h
        src/list/s21_list_test.cpp
)
target_link_libraries(list gtest pthread)


add_executable(
        queue
        src/queue/s21_queue.cpp
        src/queue/s21_queue.h
        src/queue/s21_queue_test.cpp
)
target_link_libraries(queue gtest pthread)

add_executable(
        stack
        src/stack/s21_stack.cpp
        src/stack/s21_stack.h
        src/stack/s21_stack_test.cpp
)
target_link_libraries(stack gtest pthread)

