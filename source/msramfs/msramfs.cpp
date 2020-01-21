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
    std::memset(buffer, 0, device.block_size());

    for (std::size_t i = 0; i < device.number_of_blocks(); ++i)
    {
        ReturnCode status = device.write(i, gsl::make_span(buffer, device.block_size()));
        switch (status)
        {
            case ReturnCode::WrongBlockNumber: return FormatReturnCode::BlockNumbersMismatch;
            case ReturnCode::NotEnoughSpaceInBlock: return FormatReturnCode::WrongBlockSize;
            case ReturnCode::Ok:
            {
            }
        }
    }
    return FormatReturnCode::Ok;
}

SuperBlock create_superblock(const BlockDevice& device)
{
    SuperBlock sb;
    const int required_number_of_inodes = device.number_of_blocks() / 10;
    const std::size_t required_size_of_inodes = required_number_of_inodes * sizeof(INode);
    const int inodes_in_superblock = (device.block_size() - sizeof(SuperBlock)) / sizeof(INode);

    const int inodes_outside_superblock = required_number_of_inodes - inodes_in_superblock;
    const int required_blocks_for_inodes = inodes_outside_superblock > 0 ?
        device.block_size() / (inodes_outside_superblock * sizeof(INode))
        : 0;

    const int inodes_per_block = device.number_of_blocks() / sizeof(INode);

    sb.number_of_inodes = inodes_in_superblock + required_blocks_for_inodes * inodes_per_block;
    sb.number_of_data_blocks = device.number_of_blocks() - 1 - required_blocks_for_inodes;
    sb.block_size = device.block_size();

    return sb;
}

MountReturnCode MsRamFs::mount(BlockDevice& device)
{
    if (device.mounted())
    {
        return MountReturnCode::DeviceIsAlreadyMounted;
    }

    std::unique_ptr<uint8_t[]> buffer(new uint8_t[device.block_size()]);
    clear(buffer.get(), device);
    super_block_ = create_superblock(device);
    device.mount();
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

