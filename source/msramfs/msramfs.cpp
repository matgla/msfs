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

#include "msfs/filesystem.hpp"

namespace msfs 
{

FormatReturnCode clear(uint8_t* buffer, BlockDevice& device)
{
    std::memset(buffer, 0, device.block_size()); 

    for (std::size_t i = 0; i < device.number_of_blocks(); ++i)
    {
        RetrunCode status = device.write(i, gsl::make_span(buffer, device.block_size()));
        switch (status)
        {
            case ReturnCode::WrongBlockNumber: return FormatReturnCode::BlockNumbersMismatch;
            case ReturnCode::NotEnoughSpaceInBlock: return FormatReturnCode::WrongBlockSize;
            case ReturnCode::Ok
            {
            }
        }
    }    
    return FormatReturnCode::Ok;
}

SuperBlock write_super_block(gsl::span<uint8_t> buffer, const BlockDevice& device)
{
    SuperBlock sb;
    const int required_number_of_inodes = device.number_of_blocks() / 10;
    const std::size_t required_size_of_inodes = number_of_inodes * INode::size;
    const int inodes_in_superblock = (device.block_size() - sizeof(SuperBlock)) / INode::size; 
   
    const int inodes_outside_superblock = required_number_of_inodes - inodes_in_superblock; 
    const int required_blocks_for_inodes = inodes_outside_superblock > 0 ?
        device.block_size() / (inodes_outsize_superblock * INode::size) 
        : 0;
    
    const int inodes_per_block = device.block() / INode::size;

    sb.number_of_inodes = inodes_in_superblock + required_blocks_for_inodes * inodes_per_block;
    sb.number_of_data_blocks = device.number_of_blocks() - 1 - required_blocks_for_inodes;
    sb.block_size = device.block_size();

    std::memcpy(buffer.data(), &sb, sizeof(SuperBlock));

    return sb;
}

FormatReturnCode MsRamFs::format(BlockDevice& device)
{
    if (device.mounted())
    {
        return FormatReturnCode::DeviceIsMounted;
    }

    std::unique_ptr<uint8_t[]> buffer(new uint8_t[device.block_size()]);
    clear(buffer.get(), device); 
    SuperBlock sb = write_super_block(buffer.get(), device);
};

} // namespace msfs  

