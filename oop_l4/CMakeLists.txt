cmake_minimum_required(VERSION 3.10)
project(oop_l4)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(googletest)


add_executable(main main.cpp Array.h Pentagon.h Rhombus.h Trapezoid.h)


enable_testing()
add_executable(tests tests.cpp Array.h Pentagon.h Rhombus.h Trapezoid.h)
target_link_libraries(tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
