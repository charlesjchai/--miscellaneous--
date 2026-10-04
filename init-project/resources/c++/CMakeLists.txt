cmake_minimum_required(VERSION 3.15)

project(default VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(default-bin ${SOURCES})

target_include_directories(default-bin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)