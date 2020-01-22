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
#include <list>
#include <array>

#include "msfs/block_device.hpp"
#include "msfs/return_codes.hpp"

namespace msfs
{

class BlockDeviceDriverStub : public BlockDevice
{
public:
    BlockDeviceDriverStub(const std::size_t size, const std::size_t read_size,
        const std::size_t write_size, const std::size_t erase_size); 

    int init() override;
    int deinit() override;
    
    int read(std::size_t address, StreamType& stream) const override;
    int write(std::size_t address, const StreamType& stream) override;
    int erase(std::size_t address, std::size_t size) override; 
};

} // namespace msfs
