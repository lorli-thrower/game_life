cmake_minimum_required(VERSION 3.25.2)

project(life)

set (SOURCES src/main.cpp src/Life.cpp) 

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
