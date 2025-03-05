set(SOURCES 
	sorting_test.cpp
)

add_executable(sorting_test ${SOURCES})

target_link_libraries(sorting_test 
	gtest
	${SORT_LIB}
)

add_test(sorting_test sorting_test)
