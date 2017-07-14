cmake_minimum_required(VERSION 3.7)
project(Daemonizer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Daemonizer.h)
add_executable(Daemonizer ${SOURCE_FILES})