cmake_minimum_required(VERSION 3.0)
project(Integral)

set(CMAKE_CXX_STANDARD 11)

add_executable(Integral
		src/storage/storage.h
		src/storage/thread_storage.h
		src/storage/thread_storage.cpp
		src/main.cpp)