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

#include <gsl/span>

namespace msfs
{

class BlockDevice
{
public:
    using StreamType = gsl::span<uint8_t>;

    BlockDevice(const std::size_t block_size);

    virtual ~BlockDevice() = default;

    std::size_t block_size() const;
    std::size_t number_of_blocks() const;

    bool mounted() const;
    void mount() const;
    void umount() const;

    virtual int read(std::size_t block_number, StreamType& stream) = 0;
    virtual int write(std::size_t block_number, const StreamType& stream) = 0;
    
private:
    std::size_t block_size_;
    std::size_t number_of_blocks_;
};

} // namespace msfs