#include <algorithm>
#include <iostream>

#include "GodRandomizer.hpp"
#include "Types.hpp"

namespace Cyclades
{

RandomizerBase::RandomizerBase()
    : m_lastGodsSetting(ALL_GODS)
{
    m_randomizer.randomize(m_lastGodsSetting);
}

std::deque<God> FivePlayersRandomizer::randomizeGods()
{
    m_randomizer.randomize(m_lastGodsSetting);
    return m_lastGodsSetting;
}

FourPlayersRandomizer::FourPlayersRandomizer()
{
    m_lastUnavailableGod = m_lastGodsSetting.back();
    m_lastGodsSetting.pop_back();
}

std::deque<God> FourPlayersRandomizer::randomizeGods()
{
    m_randomizer.randomize(m_lastGodsSetting);

    auto l_newUnavailableGod = m_lastGodsSetting.back();

    m_lastGodsSetting.pop_back();
    m_lastGodsSetting.push_front(m_lastUnavailableGod);
    m_lastUnavailableGod = l_newUnavailableGod;

    return m_lastGodsSetting;
}

ThreePlayersRandomizer::ThreePlayersRandomizer()
    : m_state(RandomizerPhase::FirstPhase),
      m_randomizeGods({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&ThreePlayersRandomizer::randomizeFirstPhase, this)),
                        std::make_pair(RandomizerPhase::SecondPhase, std::bind(&ThreePlayersRandomizer::randomizeSecondPhase, this)) })
{

}

std::deque<God> ThreePlayersRandomizer::randomizeGods()
{
    return m_randomizeGods[m_state]();
}

std::deque<God> ThreePlayersRandomizer::randomizeFirstPhase()
{
    m_lastGodsSetting = ALL_GODS;
    m_lastUnavailableGods = {};

    m_randomizer.randomize(m_lastGodsSetting);

    int l_numberOfUnavailableGods = 2;

    for (int i = 0; i < l_numberOfUnavailableGods; i++)
    {
        m_lastUnavailableGods.push_front(m_lastGodsSetting.back());
        m_lastGodsSetting.pop_back();
    }

    changePhase(RandomizerPhase::SecondPhase);
    return m_lastGodsSetting;
}

std::deque<God> ThreePlayersRandomizer::randomizeSecondPhase()
{
    m_lastGodsSetting.swap(m_lastUnavailableGods);
    changePhase(RandomizerPhase::FirstPhase);
    return m_lastGodsSetting;
}

void ThreePlayersRandomizer::changePhase(RandomizerPhase p_phase)
{
    m_state = p_phase;
}
}
