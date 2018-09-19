#pragma once

#include <iostream>
#include "Types.hpp"
#include "GodRandomizerFactory.hpp"
#include "IGodRandomizer.hpp"

namespace Cyclades
{

class ControlBoard
{
public:
    ControlBoard(NumberOfPlayers p_numberOfPlayers)
        :   m_godRandomizer(GodRandomizerFactory().createGodRandomizer(p_numberOfPlayers))
    {
    }

    void printGods()
    {
        for (auto l_god : m_godRandomizer->randomizeGods())
        {
            std::cout << l_god << std::endl;
        }
        std::cout << std::endl;
    }

private:
    std::unique_ptr<IGodRandomizer> m_godRandomizer;
};

}
