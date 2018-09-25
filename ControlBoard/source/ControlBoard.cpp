#include <iostream>

#include "ControlBoard.hpp"
#include "Types.hpp"
#include "GodGeneratorFactory.hpp"
//#include "ICreatureRandomizer.hpp"
#include "IGodGenerator.hpp"

namespace Cyclades
{

ControlBoard::ControlBoard(NumberOfPlayers p_numberOfPlayers)
    :   m_godGenerator(GodGeneratorFactory::createGodGenerator(p_numberOfPlayers))
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

}
