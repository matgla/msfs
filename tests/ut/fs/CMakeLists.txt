# This file is part of MSOS project. This is simple OS for embedded development devices.
# Copyright (C) 2019 Mateusz Stadnik
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

add_executable(fs_tests)

target_sources(fs_tests
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/BlockDeviceDriverStub.hpp

        ${CMAKE_CURRENT_SOURCE_DIR}/stubs/BlockDeviceDriverStub.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MsTmpFsTests.cpp
)

target_link_libraries(fs_tests
    PRIVATE
        gtest
        gmock
        gtest_main
        msfs_mstmpfs
)

target_include_directories(fs_tests
    PUBLIC
        "${PROJECT_SOURCE_DIR}"
)

