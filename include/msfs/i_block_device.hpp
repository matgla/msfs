#pragma once

#include <cstdint>

#include <gsl/span>

namespace msfs
{

class BlockDevice
{
public:
    using StreamType = gsl::span<uint8_t>;

    std::size_t block_size() const;

    virtual int read(std::size_t block_number, StreamType& stream) = 0;
    virtual int write(std::size_t block_number, const StreamType& stream) = 0;
};

} // namespace msfs
