#pragma once

#include <memory>

namespace Cyclades
{

enum class NumberOfPlayers;
class IGodRandomizer;

class GodRandomizerFactory
{
public:
    static std::unique_ptr<IGodRandomizer> createGodRandomizer(NumberOfPlayers p_numberOfPlayers);
};

}
