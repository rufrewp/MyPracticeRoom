cmake_minimum_required(VERSION 3.8)

add_executable(Lab1_task1 src/task1.c)
add_executable(Lab1_task2 src/task2.c)
add_executable(Lab1_task3 src/task3.c)
add_executable(Lab1_task4 src/task4.c)
add_executable(Lab1_task5 src/task5_main.c src/task5_func.c)
add_executable(Lab1_task6 src/task6_main.c src/task6_func.c)
add_executable(Lab1_task7 src/task7_main.c src/task7_func.c)
add_executable(Lab1_task8 src/task7_main.c)

add_library(Lab1_task8_lib STATIC src/task7_func.c)

target_link_libraries(Lab1_task8 Lab1_task8_lib)
