#include <utility>

#include "GodRandomizer.hpp"
#include "Types.hpp"

namespace Cyclades
{

constexpr int ONE_UNAVAILABLE_GOD = 1;
constexpr int TWO_UNAVAILABLE_GODS = 2;

RandomizerBase::RandomizerBase(const RandomizeGods& p_phases)
    : m_state(RandomizerPhase::FirstPhase),
      m_randomizeGods(p_phases),
      m_lastAvailableGods(ALL_GODS),
      m_lastUnavailableGods({})
{
}

std::deque<God> RandomizerBase::randomizeGods()
{
    m_randomizeGods.at(m_state)();

    return m_lastAvailableGods;
}

void RandomizerBase::changePhase(RandomizerPhase p_phase)
{
    if(m_randomizeGods.find(p_phase) != m_randomizeGods.end())
    {
        m_state = p_phase;
    }
}

void RandomizerBase::commonRandomize(const int p_numberOfUnavailableGods)
{
    m_lastAvailableGods.swap(m_lastUnavailableGods);
    m_randomizer.randomize(m_lastUnavailableGods);

    const auto& l_firstElementToMove = m_lastUnavailableGods.begin();
    const auto& l_lastElementToMove = m_lastUnavailableGods.end() - p_numberOfUnavailableGods;

    m_lastAvailableGods.insert(m_lastAvailableGods.end(), l_firstElementToMove, l_lastElementToMove);
    m_lastUnavailableGods.erase(l_firstElementToMove, l_lastElementToMove);
}


FivePlayersRandomizer::FivePlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&FivePlayersRandomizer::randomize, this)) })
{
}

void FivePlayersRandomizer::randomize()
{
    m_randomizer.randomize(m_lastAvailableGods);
}

FourPlayersRandomizer::FourPlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&FourPlayersRandomizer::randomize, this))})
{
}

void FourPlayersRandomizer::randomize()
{
    commonRandomize(ONE_UNAVAILABLE_GOD);
}

ThreePlayersRandomizer::ThreePlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&ThreePlayersRandomizer::randomizeFirstPhase, this)),
                       std::make_pair(RandomizerPhase::SecondPhase, std::bind(&ThreePlayersRandomizer::randomizeSecondPhase, this)) })
{
}

void ThreePlayersRandomizer::randomizeFirstPhase()
{
    resetGods();
    commonRandomize(TWO_UNAVAILABLE_GODS);

    changePhase(RandomizerPhase::SecondPhase);
}

void ThreePlayersRandomizer::randomizeSecondPhase()
{
    m_lastAvailableGods.swap(m_lastUnavailableGods);

    changePhase(RandomizerPhase::FirstPhase);
}

void ThreePlayersRandomizer::resetGods()
{
    m_lastAvailableGods = ALL_GODS;
    m_lastUnavailableGods = {};
}

}
