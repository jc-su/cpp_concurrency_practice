cmake_minimum_required(VERSION 3.21)
project(concurrency_practice)

set(CMAKE_CXX_STANDARD 20)

find_package(Threads)

add_subdirectory(src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        add_compile_options(-Wno-unused-local-typedef)
    else ()
        add_compile_options(/W4 /WX)
    endif ()
else ()
    if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
        add_compile_options(-O2 -g)
    else ()
        add_compile_options(/O2 /Zi)
    endif ()
endif ()
