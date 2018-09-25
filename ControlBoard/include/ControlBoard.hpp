#pragma once

#include <memory>

namespace Cyclades
{

enum class NumberOfPlayers;
class ICreatureRandomizer;
class IGodGenerator;

class ControlBoard
{
public:
    ControlBoard(NumberOfPlayers p_numberOfPlayers);
    ~ControlBoard();

    //printGods() is temporary for output testing
    void printGods();
private:
    //std::unique_ptr<ICreatureRandomizer> m_creatureRandomizer;
    std::unique_ptr<IGodGenerator> m_godGenerator;
};

}
