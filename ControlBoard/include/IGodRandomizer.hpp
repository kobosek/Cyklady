#pragma once

#include <deque>

namespace Cyclades
{

enum class God;

class IGodRandomizer
{
public:
    virtual ~IGodRandomizer() = default;
    virtual std::deque<God> randomizeGods() = 0;
};

}

