#include <vector>
#include <memory>
#include <iostream>

#include "ControlBoard.hpp"
#include "Types.hpp"

using namespace Cyclades;

int main()
{
    try
    {
        ControlBoard l_controlBoard(NumberOfPlayers::Three);

        //FOR TESTING PURPOSES RANDOMIZE 10 times for four players
        for (int i = 0; i < 10; ++i)
        {
            l_controlBoard.printGods();
        }
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 0;
    }

    return 0;
}
