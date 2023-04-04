cmake_minimum_required(VERSION 3.13)  # CMake version check

project(ASD)               # Create project "simple_example"

set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(first_assignment Assignment/old_assignments/first_assignment/main.cpp)

add_executable(second_assignment Assignment/old_assignments/second_assignment/main.cpp)

add_executable(third_assignment Assignment/old_assignments/third_assignment/main.cpp)
add_executable(PalindromeString "Exercises/Dynamic Progr/PalindromeString.cpp")
add_executable(exercise1 Exercises/Trees/exercise1.cpp)
add_executable(sortingexercises Exercises/Sorting/sortingexercises.cpp)
add_executable(efficientprogramming "Exercises/Efficient Programming/efficientprogramming.cpp")
add_executable(sorting "Theory/3 - Sorting/sorting.cpp")
add_executable(ex1 "Assignment/Ass22_23/1 - First/ex1.cpp")
add_executable(GeneralTree "Theory/2 - Tree/GeneralTree.cpp")
add_executable(bst "Theory/2 - Tree/bst.cpp")
add_executable(BinaryTree Exercises/Trees/BinaryTree.cpp)
add_executable(dynamicprogramming "Theory/7 - Dynamic Programming/dynamicprogramming.cpp")
add_executable(BinaryHeap "Theory/4 - Heap/BinaryHeap.cpp")