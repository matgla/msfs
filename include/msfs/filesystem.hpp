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

#include "msos/block_device.hpp"

namespace msfs
{

enum class MountReturnCode
{
    Ok
};

enum class FormatReturnCode
{
    Ok,
    DeviceIsMounted,
    BlockNumbersMismatch,
    WrongBlockSize
};

class FileSystem
{
public:
    virtual ~FileSystem() = default;

    virtual MountReturnCode mount(BlockDevice& device) = 0;
    
    virtual std::size_t create() = 0; 
    virtual bool remove(std::size_t inode_index) = 0;
    virtual std::size_t stat(std::size_t inode_index) = 0;

protected:
    static bool mounted_;
};

} // namespace msfs 

