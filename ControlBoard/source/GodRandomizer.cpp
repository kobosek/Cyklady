#include <algorithm>

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

std::deque<God> ThreePlayersRandomizer::randomizeGods()
{
    return std::deque<God>();
}

}
