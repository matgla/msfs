// This file is part of MSOS project.
// Copyright (C) 2020 Mateusz Stadnik
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <gtest/gtest.h>

#include "tests/ut/fs/stubs/BlockDeviceDriverStub.hpp"
#include "msfs/mstmpfs/mstmpfs.hpp"

namespace msfs
{

TEST(MsTmpFsShould, NotMountIfMounted)
{
    BlockDeviceDriverStub block_device(128, 4, 4, 32);

    mstmpfs::MsTmpFs sut;
    EXPECT_EQ(MountReturnCode::Ok, sut.mount(block_device));
    EXPECT_EQ(MountReturnCode::DeviceIsAlreadyMounted, sut.mount(block_device));
}

} // namespace msfs

