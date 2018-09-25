#pragma once

#include "ICreatureGenerator.hpp"
#include "CardShuffler.hpp"
namespace Cyclades
{

class CreatureGenerator : public ICreatureGenerator
{
public:
    CreatureGenerator();
    std::deque<Creature> generateCreatures() override;
private:
    std::deque<Creature> m_stackedCreatures;
    std::deque<Creature> m_lastAvailableCreatures;
    std::deque<Creature> m_discardedCreatures;
    CardShuffler m_shuffler;
};

}
