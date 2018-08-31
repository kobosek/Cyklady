#include <vector>
#include <memory>
#include <iostream>
#include "GodRandomizerFactory.hpp"
#include "IGodRandomizer.hpp"

using namespace Cyclades;

int main()
{
    GodRandomizerFactory l_godRandomizerProvider;

    try
    {
        auto l_godRandomizer = l_godRandomizerProvider.createGodRandomizer(NumberOfPlayers::Four);

        //FOR TESTING PURPOSES RANDOMIZE 10 times for four players
        for (int i = 0; i < 10; ++i)
        {
            auto l_godsSetting = l_godRandomizer->randomizeGods();

            for (auto l_god : l_godsSetting)
            {
                std::cout << l_god << std::endl;
            }

            std::cout << std::endl;
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Invalid number of players: " << e.what() << std::endl;
        return 0;
    }

    return 0;
}
