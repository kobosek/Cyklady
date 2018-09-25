#include <iostream>

#include "ControlBoard.hpp"
#include "Types.hpp"
#include "GodGeneratorFactory.hpp"
#include "IGodGenerator.hpp"
#include "CreatureGenerator.hpp"

namespace Cyclades
{

ControlBoard::ControlBoard(NumberOfPlayers p_numberOfPlayers)
    :   m_godGenerator(GodGeneratorFactory::createGodGenerator(p_numberOfPlayers)),
        m_creatureGenerator(std::make_unique<CreatureGenerator>())
{
}

ControlBoard::~ControlBoard()
{
}

void ControlBoard::printGods()
{
    for (auto l_god : m_godGenerator->generateGods())
    {
        std::cout << l_god << std::endl;
    }
    std::cout << std::endl;
}

void ControlBoard::printCreatures()
{
    for (auto l_creature : m_creatureGenerator->generateCreatures())
    {
        std::cout << l_creature << std::endl;
    }
    std::cout << std::endl;
}

}
