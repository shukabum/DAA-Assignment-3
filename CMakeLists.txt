# CMake minimum version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ClimbingBoulder VERSION 1.0)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable target with the name 'climbing_boulder'
add_executable(climbing_boulder 
    main.cpp 
    greedyPathCount.cpp
    greedyMaxReward.cpp 
    optimalMaxReward.cpp
)

# Optional: Enable compiler warnings for better code quality
target_compile_options(climbing_boulder PRIVATE -Wall -Wextra -Wpedantic)
