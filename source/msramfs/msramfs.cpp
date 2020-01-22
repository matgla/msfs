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

#include "msfs/msramfs/msramfs.hpp"

#include <cstring>

#include "msfs/filesystem.hpp"
#include "msfs/return_codes.hpp"

namespace msfs
{
namespace msramfs
{
FormatReturnCode clear(uint8_t* buffer, BlockDevice& device)
{
    return FormatReturnCode::Ok;
}

SuperBlock create_superblock(const BlockDevice& device)
{
    return {};
}

MountReturnCode MsRamFs::mount(BlockDevice& device)
{
    return MountReturnCode::Ok;
};

std::size_t MsRamFs::create()
{
    return 1;
}

bool MsRamFs::remove(std::size_t inode_index)
{
    return true;
}

std::size_t MsRamFs::stat(std::size_t inode_index)
{
    return 0;
}

} // namespace msramfs
} // namespace msfs

