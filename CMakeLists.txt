cmake_minimum_required(VERSION 3.13)

project(coursera)

set(CMAKE_CXX_STANDARD 17)

add_executable(coursera main.cpp list.h list.cpp Stack.cpp Stack.h Queue.h Deque.h)