
target_sources(longNums_lib
	PRIVATE
		long_number.cpp
	PUBLIC
		long_number.hpp
)

target_include_directories(longNums_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
