#include "CreatureGenerator.hpp"
#include "Types.hpp"

namespace Cyclades
{

CreatureGenerator::CreatureGenerator()
    : m_stackedCreatures(ALL_CREATURES),
      m_lastAvailableCreatures({ Creature::Empty, Creature::Empty, Creature::Empty }),
      m_discardedCreatures({})
{
    m_shuffler.shuffle(m_stackedCreatures);
}

std::deque<Creature> CreatureGenerator::generateCreatures()
{
    m_lastAvailableCreatures.push_back(m_stackedCreatures.front());
    m_stackedCreatures.pop_front();


    auto l_newDiscardedCreature = m_lastAvailableCreatures.front();

    if (l_newDiscardedCreature != Creature::Empty)
    {
        m_discardedCreatures.push_front(l_newDiscardedCreature);
    }

    m_lastAvailableCreatures.pop_front();

    return m_stackedCreatures;
}

}
