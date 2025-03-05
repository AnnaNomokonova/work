project(sort)

set(SORT_LIB "sort_lib")
add_library(${SORT_LIB} "")

add_subdirectory(src)
add_subdirectory(test)
