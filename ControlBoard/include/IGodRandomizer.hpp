#pragma once

#include <vector>

namespace Cyclades
{

enum class God;

class IGodRandomizer
{
public:
    virtual ~IGodRandomizer() = default;
    virtual std::vector<God> randomizeGods() = 0;
};

}

