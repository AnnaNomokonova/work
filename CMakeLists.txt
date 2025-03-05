cmake_minimum_required(VERSION 3.2...3.27.5)

project(MySortingProject)

enable_testing()
add_subdirectory(lib/googletest)

add_subdirectory(menu)
add_subdirectory(sort)

