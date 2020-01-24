cmake_minimum_required(VERSION 3.1)

project(msfs CXX)

add_subdirectory(lib)

add_library(msfs INTERFACE)

set (include_dir "${PROJECT_SOURCE_DIR}/include/msfs")

add_library(msfs_mstmpfs STATIC)

target_sources(msfs_mstmpfs
    PUBLIC
        ${include_dir}/block_device.hpp
        ${include_dir}/mstmpfs/mstmpfs.hpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/source/block_device.cpp
        ${PROJECT_SOURCE_DIR}/source/mstmpfs/mstmpfs.cpp
)

target_include_directories(msfs_mstmpfs
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(msfs_mstmpfs
    PUBLIC
        GSL
        eul
)

target_compile_options(msfs_mstmpfs PUBLIC
    $<$<COMPILE_LANGUAGE:CXX>:-std=c++2a -Wall -Werror -Wextra -Wpedantic -Wconversion -Wcast-align -Wunused -Wshadow -Wold-style-cast -Wpointer-arith -Wcast-qual -Wno-missing-braces>
    $<$<CONFIG:DEBUG>:-Og -g>
    $<$<CONFIG:RELEASE>:-Os>
)

if (NOT DISABLE_TESTS)
    include (${PROJECT_SOURCE_DIR}/cmake/GitModules.cmake)
    add_subdirectory(tests/ut)
endif ()

