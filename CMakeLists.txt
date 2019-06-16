cmake_minimum_required(VERSION 3.0)
project(dsa C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64 -march=native -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -m64 -march=native -Wall -Wextra -Werror")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check platform
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    cmake_policy(SET  CMP0042 NEW)
endif()

file(GLOB_RECURSE CPP_SRC ${CMAKE_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE C_SRC ${CMAKE_SOURCE_DIR}/*.c)

add_library(dsa STATIC ${C_SRC} ${CPP_SRC})
