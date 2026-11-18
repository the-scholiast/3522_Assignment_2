cmake_minimum_required(VERSION 3.20)
project(assignment2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(assignment2 main.cpp City.hpp City.cpp FittestTourFinder.hpp FittestTourFinder.cpp GeneticAlgorithm.hpp GeneticAlgorithm.cpp Population.hpp Population.cpp Tour.hpp Tour.cpp)