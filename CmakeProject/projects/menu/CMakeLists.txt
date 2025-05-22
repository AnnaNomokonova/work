project(menu)

SET(CMAKE_CXX_FLAGS "-finput-charset=utf-8 -fexec-charset=utf-8")

set(SOURCES 
	main.cpp
	menu_functions.cpp
	menu_items.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
