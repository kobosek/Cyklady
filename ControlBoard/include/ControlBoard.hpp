#pragma once

#include <memory>

namespace Cyclades
{

enum class NumberOfPlayers;
class ICreatureRandomizer;
class IGodRandomizer;

class ControlBoard
{
public:
    ControlBoard(NumberOfPlayers p_numberOfPlayers);
    ~ControlBoard();

    void printGods();
private:
    //std::unique_ptr<ICreatureRandomizer> m_creatureRandomizer;
    std::unique_ptr<IGodRandomizer> m_godRandomizer;
};

}
