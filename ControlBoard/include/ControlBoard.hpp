#pragma once

#include <memory>

namespace Cyclades
{

enum class NumberOfPlayers;
class IGodGenerator;
class ICreatureGenerator;

class ControlBoard
{
public:
    ControlBoard(NumberOfPlayers);
    ~ControlBoard();

    //printGods() and printCreatures() are temporary for output testing
    void printGods();
    void printCreatures();
private:
    std::unique_ptr<IGodGenerator> m_godGenerator;
    std::unique_ptr<ICreatureGenerator> m_creatureGenerator;
};

}
