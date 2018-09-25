#include "GodGenerator.hpp"
#include "Types.hpp"

namespace Cyclades
{

constexpr int ONE_UNAVAILABLE_GOD = 1;
constexpr int TWO_UNAVAILABLE_GODS = 2;

GodGeneratorBase::GodGeneratorBase()
    : m_lastAvailableGods(ALL_GODS),
      m_lastUnavailableGods({})
{
}

void GodGeneratorBase::commonGenerate(int p_numberOfUnavailableGods)
{
    m_lastAvailableGods.swap(m_lastUnavailableGods);
    m_shuffler.shuffle(m_lastUnavailableGods);

    const auto& l_firstElementToMove = m_lastUnavailableGods.begin();
    const auto& l_lastElementToMove = m_lastUnavailableGods.end() - p_numberOfUnavailableGods;

    m_lastAvailableGods.insert(m_lastAvailableGods.end(), l_firstElementToMove, l_lastElementToMove);
    m_lastUnavailableGods.erase(l_firstElementToMove, l_lastElementToMove);
}

std::deque<God> FivePlayersGodGenerator::generateGods()
{
    m_shuffler.shuffle(m_lastAvailableGods);

    return m_lastAvailableGods;
}

std::deque<God> FourPlayersGodGenerator::generateGods()
{
    commonGenerate(ONE_UNAVAILABLE_GOD);

    return m_lastAvailableGods;
}

ThreePlayertsGodGenerator::ThreePlayertsGodGenerator()
    :   m_currentGenerateFunction(std::bind(&ThreePlayertsGodGenerator::generateFirstPhase, this))
{
}

std::deque<God> ThreePlayertsGodGenerator::generateGods()
{
    m_currentGenerateFunction();

    return m_lastAvailableGods;
}

void ThreePlayertsGodGenerator::generateFirstPhase()
{
    resetGods();
    commonGenerate(TWO_UNAVAILABLE_GODS);

    changePhase(std::bind(&ThreePlayertsGodGenerator::generateSecondPhase, this));
}

void ThreePlayertsGodGenerator::generateSecondPhase()
{
    m_lastAvailableGods.swap(m_lastUnavailableGods);

    changePhase(std::bind(&ThreePlayertsGodGenerator::generateFirstPhase, this));
}


void ThreePlayertsGodGenerator::resetGods()
{
    m_lastAvailableGods = ALL_GODS;
    m_lastUnavailableGods = {};
}

void ThreePlayertsGodGenerator::changePhase(const GenerateFunction& p_generateFunction)
{
    if(p_generateFunction != nullptr)
    {
        m_currentGenerateFunction = p_generateFunction;
    }
}

}
