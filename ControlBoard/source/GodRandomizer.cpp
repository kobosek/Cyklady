#include <algorithm>
#include "GodRandomizer.hpp"

namespace Cyclades
{

std::vector<God> FivePlayersRandomizer::randomizeGods()
{
    m_randomizer.randomize(m_lastGodsSetting);
    return m_lastGodsSetting;
}

FourPlayersRandomizer::FourPlayersRandomizer()
{
    m_randomizer.randomize(m_lastGodsSetting);
    auto l_unavailableGodIt = m_lastGodsSetting.end() - 1;
    m_lastUnavailableGod = *l_unavailableGodIt;
    m_lastGodsSetting.erase(l_unavailableGodIt);
}

std::vector<God> FourPlayersRandomizer::randomizeGods()
{
    m_randomizer.randomize(m_lastGodsSetting);

    auto l_newUnavailableGodIt = m_lastGodsSetting.end() - 1;
    auto l_newUnavailableGod = *l_newUnavailableGodIt;

    m_lastGodsSetting.erase(l_newUnavailableGodIt);

    m_lastGodsSetting.push_back(m_lastUnavailableGod);
    m_randomizer.randomize(m_lastGodsSetting);

    m_lastUnavailableGod = l_newUnavailableGod;

    return m_lastGodsSetting;
}

std::vector<God> ThreePlayersRandomizer::randomizeGods()
{
    return std::vector<God>();
}

}
