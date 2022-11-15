cmake_minimum_required(VERSION 3.21)
project(containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/list)
include_directories(src/map)
include_directories(src/queue)
include_directories(src/set)
include_directories(src/stack)
include_directories(src/vector)

add_executable(containers
#        src/list/s21_list.cpp
#        src/list/s21_list.h
#        src/list/additional_methods.cpp
#        src/list/s21_list_test.cpp

        src/map/s21_map.cpp
        src/map/s21_map.h

        src/queue/s21_queue.cpp
        src/queue/s21_queue.h

        src/set/s21_set.cpp
        src/set/s21_set.h

        src/stack/s21_stack.cpp
        src/stack/s21_stack.h
#        src/stack/temp.cpp

        src/vector/s21_vector.cpp
        src/vector/s21_vector.h
        src/vector/temp.cpp

        src/s21_containers.h)
