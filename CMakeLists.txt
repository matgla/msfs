cmake_minimum_required(VERSION 3.1)

project(msfs CXX)

add_subdirectory(lib)

add_library(msfs INTERFACE)

set (include_dir "${PROJECT_SOURCE_DIR}/include/msfs")

add_library(msfs_msramfs STATIC)


target_sources(msfs_msramfs
    PUBLIC
        ${include_dir}/block_device.hpp
        ${include_dir}/msramfs/msramfs.hpp
    PRIVATE
        ${PROJECT_SOURCE_DIR}/source/block_device.cpp
        ${PROJECT_SOURCE_DIR}/source/msramfs/msramfs.cpp
)

target_include_directories(msfs_msramfs
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(msfs_msramfs
    PUBLIC
        gsl
)

if (NOT DISABLE_TESTS)
    include (${PROJECT_SOURCE_DIR}/cmake/GitModules.cmake)
    add_subdirectory(tests/ut)
endif ()

