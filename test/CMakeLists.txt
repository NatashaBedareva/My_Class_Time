cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        )

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_time_app test_time.cpp) # to run tests
target_link_libraries(test_time_app PRIVATE GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(test_time_app)

#cmake --build build
#cd build/test/
# ctest
#./Debug/test_time_app

