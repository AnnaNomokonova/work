add_executable(ilyatest ilyatest.cpp)
target_link_libraries(ilyatest
	gtest_main
	longNums_lib
)

add_test(ilyatest ilyatest)
