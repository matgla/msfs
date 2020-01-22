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

#include "tests/ut/fs/stubs/BlockDeviceDriverStub.hpp"

namespace msfs
{

BlockDeviceDriverStub::BlockDeviceDriverStub(const std::size_t size,
    const std::size_t read_size, const std::size_t write_size, 
    const std::size_t erase_size) 
    : BlockDevice(size, read_size, write_size, erase_size)
{
}

int BlockDeviceDriverStub::init() 
{
    return 0;
}

int BlockDeviceDriverStub::deinit() 
{
    return 0;
}

int BlockDeviceDriverStub::read(std::size_t address, StreamType& stream) const 
{
    return 0;
}

int BlockDeviceDriverStub::write(std::size_t address, const StreamType& stream)  
{
    return 0;
}


int BlockDeviceDriverStub::erase(std::size_t address, std::size_t size) 
{
    return 0;
}

} // namespace msfs 

