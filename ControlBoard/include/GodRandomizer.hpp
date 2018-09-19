#pragma once

#include <random>
#include "IGodRandomizer.hpp"
#include "Randomizer.hpp"

namespace Cyclades
{

class RandomizerBase : public IGodRandomizer
{
public:
    virtual ~RandomizerBase() = default;
protected:
    std::vector<God> m_lastGodsSetting = ALL_GODS;
    Randomizer m_randomizer;
};

class FivePlayersRandomizer : public RandomizerBase
{
public:
    std::vector<God> randomizeGods() override;
};

class FourPlayersRandomizer : public RandomizerBase
{
public:
    FourPlayersRandomizer();
    std::vector<God> randomizeGods() override;
private:
    God m_lastUnavailableGod;
};

class ThreePlayersRandomizer : public RandomizerBase
{
public:
    std::vector<God> randomizeGods() override;
};

}
