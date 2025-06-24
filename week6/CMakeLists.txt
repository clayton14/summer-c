cmake_minimum_required(VERSION 3.24)
project(week-6)

set(CMAKE_C_STANDARD 23) 
set(CMAKE_C_STANDARD_REQUIRED ON) 

# list of c files to compile
set(SOURCES
    src/employee.c
    src/main.c
)

# gcc compile options
add_compile_options(-Wall -Wextra -save-temps)

add_executable(${PROJECT_NAME} SOURCES)

target_include_directories(hello_headers
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)