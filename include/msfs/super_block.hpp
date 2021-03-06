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

struct SuperBlock
{
    char magic_byte[4] = {'M', 'R', 'F', 'S'};
    uint16_t inodes_bitmap_size;
    uint16_t data_bitmap_size;
    uint16_t number_of_data_blocks;
    uint16_t number_of_inodes;
    std::size_t block_size;
};

} // namespace msfs
