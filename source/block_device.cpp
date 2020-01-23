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

#include "msfs/block_device.hpp"

#include <eul/utils/unused.hpp>

namespace msfs
{

BlockDevice::BlockDevice(const std::size_t size, const std::size_t read_size,
    const std::size_t write_size, const std::size_t erase_size)
    : size_(size)
    , read_size_(read_size)
    , write_size_(write_size)
    , erase_size_(erase_size)
{
}

SyncStatus BlockDevice::sync()
{
    return SyncStatus::Ok;
}

std::size_t BlockDevice::read_size() const
{
    return read_size_;
}

std::size_t BlockDevice::write_size() const
{
    return write_size_;
}

std::size_t BlockDevice::erase_size() const
{
    return erase_size_;
}

std::size_t BlockDevice::erase_size_at_address(std::size_t address) const
{
    UNUSED1(address);

    return erase_size_;
}

std::size_t BlockDevice::size() const
{
    return size_;
}

ReadStatus BlockDevice::read(std::size_t address, StreamType& stream) const
{
    if (!is_read_valid(address, stream))
    {
        return ReadStatus::Fail;
    }

    perform_read(address, stream);
    return ReadStatus::Ok;
}

WriteStatus BlockDevice::write(std::size_t address, const StreamType& stream)
{
    if(!is_write_valid(address, stream))
    {
        return WriteStatus::Fail;
    }
    perform_write(address, stream);
    return WriteStatus::Ok;
}

EraseStatus BlockDevice::erase(std::size_t address, std::size_t size)
{
    if(!is_erase_valid(address, size))
    {
        return EraseStatus::Fail;
    }
    perform_erase(address, size);
    return EraseStatus::Ok;
}

bool BlockDevice::is_write_valid(std::size_t address, const StreamType& stream) const
{
    if (address % write_size() != 0) return false;
    if (static_cast<std::size_t>(stream.size()) != write_size()) return false;
    if (address + stream.size() > size()) return false;
    return true;
}

bool BlockDevice::is_read_valid(std::size_t address, StreamType& stream) const
{
    if (address % read_size() != 0) return false;
    if (static_cast<std::size_t>(stream.size()) != read_size()) return false;
    if (address + stream.size() > size()) return false;

    return true;
}

bool BlockDevice::is_erase_valid(std::size_t address, std::size_t size) const
{
    if (address % erase_size_at_address(address) != 0) return false;
    if (address + size != erase_size_at_address(address)) return false;
    if (address + size > this->size()) return false;

    return true;
}

} // namespace msfs

