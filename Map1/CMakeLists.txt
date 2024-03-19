cmake_minimum_required(VERSION 3.24)
project(Map1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Map1 App.cpp ExtendedTest.cpp ExtendedTest.h Map.cpp Map.h MapIterator.cpp MapIterator.h ShortTest.cpp ShortTest.h)
