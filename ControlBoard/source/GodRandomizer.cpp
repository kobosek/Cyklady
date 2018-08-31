#include <algorithm>
#include "GodRandomizer.hpp"

namespace Cyclades
{
RandomizerBase::RandomizerBase() :
    m_lastGodsSetting(ALL_GODS)
{}

std::vector<God> FivePlayersRandomizer::randomizeGods()
{
    m_randomizer.randomize(m_lastGodsSetting);
    return m_lastGodsSetting;
}

std::vector<God> FourPlayersRandomizer::randomizeGods()
{
    auto l_lastUsedIt = (m_lastUnavailableGod != God::Empty) ? m_lastGodsSetting.end() - 1
                                                             : m_lastGodsSetting.end();

    std::vector<God> l_newGodsSetting(m_lastGodsSetting.begin(), l_lastUsedIt);

    m_randomizer.randomize(l_newGodsSetting);

    auto l_newUnavailableGodIt = l_newGodsSetting.end() - 1;
    auto l_newUnavailableGod = *l_newUnavailableGodIt;

    l_newGodsSetting.erase(l_newUnavailableGodIt);

    if (m_lastUnavailableGod != God::Empty)
    {
        l_newGodsSetting.push_back(m_lastUnavailableGod);
        m_randomizer.randomize(l_newGodsSetting);
    }

    l_newGodsSetting.push_back(God::Empty);
    m_lastUnavailableGod = l_newUnavailableGod;
    m_lastGodsSetting = l_newGodsSetting;

    return m_lastGodsSetting;
}

std::vector<God> ThreePlayersRandomizer::randomizeGods()
{
    return std::vector<God>();
}

}
