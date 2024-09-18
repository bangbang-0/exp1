cmake_minimum_required(VERSION 3.28)
project(exp1)

set(CMAKE_CXX_STANDARD 17)


set(EXECUTABLE_OUTPUT_PATH  "${PROJECT_SOURCE_DIR}/bin")

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_executable(exp1 ${SOURCES})