target_sources(${SORT_LIB} 
	PRIVATE
		insert_sort.cpp
	PUBLIC
		insert_sort.hpp
)

target_include_directories(${SORT_LIB} PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)
