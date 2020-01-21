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

#pragma once

#include <cstdint>

#include "msfs/block_device.hpp"
#include "msfs/filesystem.hpp"

namespace msfs
{
namespace msramfs
{

struct SuperBlock
{
    char magic_byte[4] = {'M', 'R', 'F', 'S'};
    uint16_t inodes_bitmap_size; 
    uint16_t data_bitmap_size;
    uint16_t number_of_data_blocks;
    uint16_t number_of_inodes;
    std::size_t block_size;
};

struct INode
{
    uint8_t valid;

    uint32_t file_size;
    
    uint32_t direct_pointers[12];
    uint32_t indirect_pointer;
    uint32_t double_indirect_pointer;
    uint32_t triple_indirect_pointer; 
};

class MsRamFs : public FileSystem
{
public:
    static FormatReturnCode format(BlockDevice& device);

    MountReturnCode mount(BlockDevice& device) override;

    std::size_t create() override;
    bool remove(std::size_t inode_index) override;
    std::size_t stat(std::size_t inode_index) override;

private:
    SuperBlock* super_block_;
};

} // namespace msfs
} // namespace msos

