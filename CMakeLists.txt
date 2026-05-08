cmake_minimum_required(VERSION 3.12)
project(dsa C CXX)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if (NOT WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
endif()
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CMAKE_CURRENT_SOURCE_DIR}/include/bits/stdc++.h")
endif()

# For each enabled directory, glob all .c/.cpp files with CONFIGURE_DEPENDS
# so that newly added files are picked up on next cmake re-run.

function(compile_dir DIR_NAME)
    file(GLOB SRCS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${DIR_NAME}/*.c ${CMAKE_CURRENT_SOURCE_DIR}/${DIR_NAME}/*.cpp)
    foreach(SRC ${SRCS})
        get_filename_component(NAME ${SRC} NAME_WE)
        set(TARGET "${DIR_NAME}-${NAME}")
        add_executable(${TARGET} ${SRC})
        set_target_properties(${TARGET} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${DIR_NAME})
    endforeach()
endfunction()

if(hihocoder)
    compile_dir(hihoCoder)
endif()

if(leetcode)
    compile_dir(leetcode)
endif()

if(use_51nod)
    compile_dir(51nod)
endif()

if(luogu)
    compile_dir(luogu)
endif()

if(cf)
    compile_dir(cf)
endif()
