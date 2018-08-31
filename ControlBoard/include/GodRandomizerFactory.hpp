#pragma once

#include <memory>
#include "Types.hpp"

namespace Cyclades
{

class IGodRandomizer;

class GodRandomizerFactory
{
public:
    std::unique_ptr<IGodRandomizer> createGodRandomizer(NumberOfPlayers p_numberOfPlayers);
};

}
