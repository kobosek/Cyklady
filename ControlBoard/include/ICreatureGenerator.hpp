#pragma once

#include <deque>

namespace Cyclades
{

enum class Creature;

class ICreatureGenerator
{
public:
    virtual ~ICreatureGenerator() = default;
    virtual std::deque<Creature> generateCreatures() = 0;
};

}
