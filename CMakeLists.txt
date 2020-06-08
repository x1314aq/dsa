cmake_minimum_required(VERSION 3.0)
project(dsa C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Check platform
if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    cmake_policy(SET  CMP0042 NEW)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CMAKE_CURRENT_SOURCE_DIR}/include/bits/stdc++.h")
endif()

# define a macro for later use
macro(compile DIR)
    set(DEPS)
    set(CUR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/${DIR})
    file(GLOB SRCS RELATIVE ${CUR_DIR} ${CUR_DIR}/*.c ${CUR_DIR}/*.cpp)
    foreach(TMP ${SRCS})
        string(FIND ${TMP} "." POS)
        string(SUBSTRING ${TMP} 0 ${POS} NAME)
        set(TARGET "${DIR}-${NAME}")
        add_executable(${TARGET} ${CUR_DIR}/${TMP})
        set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DIR})
        list(APPEND DEPS ${TARGET})
    endforeach()
    add_custom_target(${DIR} DEPENDS ${DEPS})
endmacro()

compile(hihoCoder)
# compile(leetcode)
compile(51nod)
compile(luogu)
compile(cf)
