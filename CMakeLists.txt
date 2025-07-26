cmake_minimum_required(VERSION 3.10)
project(MetroSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_PREFIX_PATH "D:/msys2/mingw64/lib/cmake")

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system)

include_directories(include)

file(GLOB_RECURSE SOURCES src/main.cpp)

message(STATUS "Found source files: ${SOURCES}")

add_executable(MetroSim ${SOURCES})

target_link_libraries(MetroSim sfml-graphics sfml-window sfml-system)

