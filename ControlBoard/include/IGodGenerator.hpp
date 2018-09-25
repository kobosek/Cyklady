#pragma once

#include <deque>

namespace Cyclades
{

enum class God;

class IGodGenerator
{
public:
    virtual ~IGodGenerator() = default;
    virtual std::deque<God> generateGods() = 0;
};

}

