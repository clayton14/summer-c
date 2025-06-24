cmake_minimum_required(VERSION 3.24)
project(week-6)

set(CMAKE_C_STANDARD 23) 
set(CMAKE_C_STANDARD_REQUIRED ON) 

# gcc options

add_compile_options(-Wall -Wextra -save-temps)

add_executable(${PROJECT_NAME} src/main.c)