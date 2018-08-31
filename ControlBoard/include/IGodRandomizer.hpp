#pragma once

#include "Types.hpp"

namespace Cyclades
{

class IGodRandomizer
{
public:
    virtual ~IGodRandomizer() = default;
    virtual std::vector<God> randomizeGods() = 0;
};

}

