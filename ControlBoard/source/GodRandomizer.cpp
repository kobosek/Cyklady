#include <algorithm>
#include <iostream>
#include <utility>

#include "GodRandomizer.hpp"
#include "Types.hpp"

namespace Cyclades
{

RandomizerBase::RandomizerBase(const RandomizeGods& p_phases)
    : m_state(RandomizerPhase::FirstPhase),
      m_randomizeGods(p_phases),
      m_lastGodsSetting(ALL_GODS)
{
}

std::deque<God> RandomizerBase::randomizeGods()
{
    return m_randomizeGods.at(m_state)();
}

void RandomizerBase::changePhase(RandomizerPhase p_phase)
{
    if(m_randomizeGods.find(p_phase) != m_randomizeGods.end())
    {
        m_state = p_phase;
    }
}
l
FivePlayersRandomizer::FivePlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&FivePlayersRandomizer::randomize, this)) })
{
}

std::deque<God> FivePlayersRandomizer::randomize()
{
    m_randomizer.randomize(m_lastGodsSetting);
    return m_lastGodsSetting;
}

FourPlayersRandomizer::FourPlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&FourPlayersRandomizer::randomizeFirstPhase, this)),
                       std::make_pair(RandomizerPhase::SecondPhase, std::bind(&FourPlayersRandomizer::randomizeSecondPhase, this)) })
{
    m_lastUnavailableGods.push_front(m_lastGodsSetting.back());
    m_lastGodsSetting.pop_back();
}

std::deque<God> FourPlayersRandomizer::randomizeFirstPhase()
{
    m_randomizer.randomize(m_lastGodsSetting);

    auto l_newUnavailableGod = m_lastGodsSetting.back();

    m_lastGodsSetting.pop_back();
    m_lastGodsSetting.push_front(m_lastUnavailableGods.front());
    m_lastUnavailableGods.pop_back();
    m_lastUnavailableGods.push_front(l_newUnavailableGod);

    return m_lastGodsSetting;
}

std::deque<God> FourPlayersRandomizer::randomizeSecondPhase()
{

    return m_lastGodsSetting;
}

ThreePlayersRandomizer::ThreePlayersRandomizer()
    : RandomizerBase({ std::make_pair(RandomizerPhase::FirstPhase, std::bind(&ThreePlayersRandomizer::randomizeFirstPhase, this)),
                       std::make_pair(RandomizerPhase::SecondPhase, std::bind(&ThreePlayersRandomizer::randomizeSecondPhase, this)) })
{
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
}
