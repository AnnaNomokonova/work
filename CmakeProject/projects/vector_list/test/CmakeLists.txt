add_executable(vector_tests test_vector.cpp templates_vector.cpp)
target_link_libraries(vector_tests
	gtest 
	vector_list_lib
)
add_test(test_vector vector_tests)

add_executable(doubly_linked_list_tests test_doubly_linked_list.cpp templates_doubly_linked_list.cpp)
target_link_libraries(doubly_linked_list_tests
	gtest 
	vector_list_lib
)
add_test(test_doubly_linked_list doubly_linked_list_tests)