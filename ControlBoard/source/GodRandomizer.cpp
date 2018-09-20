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

void IRandomizerPhase::changePhase(ThreePlayersRandomizer* p_randomizer, std::shared_ptr<IRandomizerPhase> p_phase)
{
    p_randomizer->changePhase(p_phase);
}

std::shared_ptr<IRandomizerPhase> FirstPhase::m_instance = std::make_shared<FirstPhase>();

std::shared_ptr<IRandomizerPhase> FirstPhase::instance()
{
    return m_instance;
}

std::deque<God> FirstPhase::randomizeGods(ThreePlayersRandomizer* p_randomizer)
{
    std::cout << "FirstPhase" << std::endl;
    changePhase(p_randomizer, SecondPhase::instance());
    return std::deque<God>();
}

std::shared_ptr<IRandomizerPhase> SecondPhase::m_instance = std::make_shared<SecondPhase>();

std::shared_ptr<IRandomizerPhase> SecondPhase::instance()
{
    return m_instance;
}

std::deque<God> SecondPhase::randomizeGods(ThreePlayersRandomizer* p_randomizer)
{
    std::cout << "SecondPhase" << std::endl;
    changePhase(p_randomizer, FirstPhase::instance());
    return std::deque<God>();
}

ThreePlayersRandomizer::ThreePlayersRandomizer()
    : m_state(std::shared_ptr<IRandomizerPhase>(FirstPhase::instance()))
{
    m_randomizer.randomize(m_lastGodsSetting);

    int l_numberOfUnavailableGods = 2;

    for (int i = 0; i < l_numberOfUnavailableGods; i++)
    {
        m_lastUnavailableGods.push_front(m_lastGodsSetting.back());
        m_lastGodsSetting.pop_back();
    }
}

std::deque<God> ThreePlayersRandomizer::randomizeGods()
{
    return m_state->randomizeGods(this);
}

void ThreePlayersRandomizer::changePhase(std::shared_ptr<IRandomizerPhase> p_phase)
{
    m_state = p_phase;
}
}
