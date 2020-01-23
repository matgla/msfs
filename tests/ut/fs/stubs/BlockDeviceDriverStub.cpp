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

#include <eul/utils/unused.hpp>

namespace msfs
{

BlockDeviceDriverStub::BlockDeviceDriverStub(const std::size_t size,
    const std::size_t read_size, const std::size_t write_size,
    const std::size_t erase_size)
    : BlockDevice(size, read_size, write_size, erase_size)
    , buffer_{}
{
    buffer_.resize(size, 0);
}

int BlockDeviceDriverStub::init()
{
    return 0;
}

int BlockDeviceDriverStub::deinit()
{
    return 0;
}

ReadStatus BlockDeviceDriverStub::perform_read(std::size_t address, StreamType& stream) const
{
    std::copy(buffer_.begin() + address, buffer_.begin() + address + stream.size(), stream.begin()); 
    return ReadStatus::Ok;
}

WriteStatus BlockDeviceDriverStub::perform_write(std::size_t address, const StreamType& stream)
{
    std::copy(stream.begin(), stream.end(), buffer_.begin() + address);
    return WriteStatus::Ok;
}


EraseStatus BlockDeviceDriverStub::perform_erase(std::size_t address, std::size_t size)
{
    std::memset(buffer_.data() + address, size);
    return EraseStatus::Ok;
}

std::string_view BlockDeviceDriverStub::name() const
{
    return "BD_STUB";
}

} // namespace msfs

