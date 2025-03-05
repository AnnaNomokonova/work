cmake_minimum_required(VERSION 3.10)

# Установите имя проекта
project(MySortingProject)

# Укажите стандарт C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем директории с заголовочными файлами
#include_directories(include)

# Создаем библиотеку из файлов с алгоритмом сортировки
#add_library(sorting hw2/insert_sort.cpp hw2/print_array.cpp hw2/randArray.cpp)

# Добавьте исполняемый файл
#add_executable(menu menu/main.cpp menu/menu_functions.cpp menu/menu_items.cpp)

# Связываем библиотеку с исполняемым файлом
#target_link_libraries(menu sorting)

# Добавляем поддиректорию для тестов
enable_testing()  # Включаем поддержку тестов
add_subdirectory(lib/googletest)

add_subdirectory(menu)
add_subdirectory(sort)

