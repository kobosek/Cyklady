#pragma once

#include <random>
#include <memory>
#include <map>
#include <functional>
#include <utility>

#include "IGodRandomizer.hpp"
#include "Randomizer.hpp"

namespace Cyclades
{

class RandomizerBase : public IGodRandomizer
{
public:
    RandomizerBase();
    virtual ~RandomizerBase() = default;
protected:
    std::deque<God> m_lastGodsSetting;
    Randomizer m_randomizer;
};

class FivePlayersRandomizer : public RandomizerBase
{
public:
    std::deque<God> randomizeGods() override;
};

class FourPlayersRandomizer : public RandomizerBase
{
public:
    FourPlayersRandomizer();
    std::deque<God> randomizeGods() override;
private:
    God m_lastUnavailableGod;
};

enum class RandomizerPhase
{
    FirstPhase,
    SecondPhase
};

using RandomizeGods = std::map<RandomizerPhase, std::function<std::deque<God>()>>;

class ThreePlayersRandomizer : public RandomizerBase
{
public:
    ThreePlayersRandomizer();
    std::deque<God> randomizeGods() override;
private:
    std::deque<God> randomizeFirstPhase();
    std::deque<God> randomizeSecondPhase();
    void changePhase(RandomizerPhase p_phase);

    RandomizerPhase m_state;
    RandomizeGods m_randomizeGods;

    std::deque<God> m_lastUnavailableGods;
};
}
