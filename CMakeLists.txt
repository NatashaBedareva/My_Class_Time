cmake_minimum_required(VERSION 3.11)
project(kvadraturawn VERSION 0.2.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option (ENABLE_TEST "Configure for MPI parallelization" ON)
if (ENABLE_TEST)
    enable_testing()
    add_subdirectory(test)
else()
    message (STATUS "no problem, building without MPI")
endif()

add_executable(kvadraturawn main.cpp)

