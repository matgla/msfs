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

template <std::size_t BlockSize, std::size_t NumberOfBlocks>
class BlockDeviceDriverStub : public BlockDevice
{
public:
    BlockDeviceDriverStub() : BlockDevice(BlockSize)
    {
    }

    int read(std::size_t block_number, StreamType& stream) override
    {
        if (block_number > NumberOfBlocks)
        {
            return ReturnCode::WrongBlockNumber;
        }

        const std::size_t size_to_copy = stream.size() >= BlockSize ? BlockSize : stream.size();

        std::copy(data_[block_number].begin(), data_[block_number].end(), stream.begin());
    }

    int write(std::size_t block_number, const StreamType& stream) override
    {
        if (block_number > NumberOfBlocks)
        {
            return ReturnCode::WrongBlockNumber;
        }

        if (stream.size() > BlockSize)
        {
            return ReturnCode::NotEnoughSpaceInBlock;
        }

        std::copy(stream.begin(), stream.end(), std::begin(data_[block_number]));
    }

private:
    std::array<std::array<uint8_t, BlockSize>, NumberOfBlocks> data_;
};

} // namespace msfs
