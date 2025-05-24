cmake_minimum_required(VERSION 3.2...3.27.5)

project(CmakeProject)

enable_testing()
add_subdirectory(lib/googletest)

# add_subdirectory(menu)
# add_subdirectory(sort)
add_subdirectory(longNums)
add_subdirectory(vector_list)

set(CMAKE_SUPRESS_REGENERATION true)
