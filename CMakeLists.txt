cmake_minimum_required(VERSION 3.13)  # CMake version check

project(ASD)               # Create project "simple_example"

set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(first_assignment Assignment/first_assignment/main.cpp)

add_executable(second_assignment Assignment/second_assignment/main.cpp)

add_executable(third_assignment Assignment/third_assignment/main.cpp)
add_executable(insertionsort "3 - Sorting/insertionsort.cpp")
add_executable(FibonacciDP "Exercises/Dynamic Progr/FibonacciDP.cpp")
add_executable(PalindromeString "Exercises/Dynamic Progr/PalindromeString.cpp")
add_executable(exercise1 Exercises/Trees/exercise1.cpp)
add_executable(exercise2 Exercises/Trees/exercise2.cpp)