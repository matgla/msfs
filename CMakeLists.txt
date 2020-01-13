cmake_minimum_required(VERSION 3.1)

project(msfs CXX)

add_library(msfs INTERFACE)

set (include_dir "${PROJECT_SOURCE_DIR}/include")

add_library(msfs_msramfs INTERFACE)
target_sources(msfs_msramfs 
    INTERFACE 
        ${include_dir}/msramfs/msramfs.hpp
)

if (NOT DISABLE_TESTS)
    include (${PROJECT_SOURCE_DIR}/cmake/GitModules.cmake)
    add_subdirectory(tests/ut)
endif ()

