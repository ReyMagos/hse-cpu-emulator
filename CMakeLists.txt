cmake_minimum_required(VERSION 3.28)
project(hse_cpu_emulator)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules")

add_library(Parser src/Parser.cpp src/handlers.cpp src/commands.cpp
        src/CPU.cpp)

add_executable(${PROJECT_NAME} src/main.cpp)
target_sources(${PROJECT_NAME}
    PUBLIC
    FILE_SET modules TYPE CXX_MODULES FILES src/Stack.cppm
)

add_executable(test src/test.cpp)
