#include <iostream>

#include "ControlBoard.hpp"
#include "Types.hpp"
#include "GodRandomizerFactory.hpp"
//#include "ICreatureRandomizer.hpp"
#include "IGodRandomizer.hpp"

namespace Cyclades
{

ControlBoard::ControlBoard(NumberOfPlayers p_numberOfPlayers)
    :   m_godRandomizer(GodRandomizerFactory::createGodRandomizer(p_numberOfPlayers))
{
}

ControlBoard::~ControlBoard()
{

}

void ControlBoard::printGods()
{
    for (auto l_god : m_godRandomizer->randomizeGods())
    {
        std::cout << l_god << std::endl;
    }
    std::cout << std::endl;
}

}
