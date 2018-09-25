#pragma once

#include <memory>

namespace Cyclades
{

enum class NumberOfPlayers;
class IGodGenerator;

class GodGeneratorFactory
{
public:
    static std::unique_ptr<IGodGenerator> createGodGenerator(NumberOfPlayers);
};

}
