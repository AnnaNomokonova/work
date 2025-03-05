# tests/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(SortingTests)

find_package(GTest REQUIRED) # Ищем библиотеку GoogleTest
include_directories(${GTEST_INCLUDE_DIRS}) # Подключаем директории GoogleTest

add_executable(sorting_test sorting_test.cpp) # Создаем исполняемый файл для тестов

target_link_libraries(sorting_test sorting ${GTEST_LIBRARIES} pthread) # Связываем с библиотеками

enable_testing() # Включаем тестирование
add_test(NAME SortingTest COMMAND sorting_test) # Добавляем тест

