#include "GodRandomizerFactory.hpp"
#include "Types.hpp"
#include "GodRandomizer.hpp"

namespace Cyclades
{

std::unique_ptr<IGodRandomizer> GodRandomizerFactory::createGodRandomizer(NumberOfPlayers p_numberOfPlayers)
{
    switch(p_numberOfPlayers)
    {
    case NumberOfPlayers::Five:
        return std::make_unique<FivePlayersRandomizer>();
    case NumberOfPlayers::Four:
        return std::make_unique<FourPlayersRandomizer>();
    case NumberOfPlayers::Three:
        return std::make_unique<ThreePlayersRandomizer>();
    default:
        throw std::invalid_argument("Invalid Number Of Players!");
    }
}

}
