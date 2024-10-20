cmake_minimum_required(VERSION 3.2)

project(memory-game)

file(GLOB src CONFIGURE_DEPENDS "src/*.hpp" "src/*.cpp")

set(CMAKE_BUILD_TYPE RELEASE)
set(CMAKE_CXX_FLAGS_RELEASE "-std=c++17 -Wall -pipe -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -DDEBUG")

add_executable(memory ${src})
