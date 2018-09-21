#pragma once

#include <random>
#include <memory>
#include <map>
#include <functional>

#include "IGodRandomizer.hpp"
#include "Randomizer.hpp"

namespace Cyclades
{

enum class RandomizerPhase
{
    FirstPhase,
    SecondPhase
};

using RandomizeGods = std::map<RandomizerPhase, std::function<std::deque<God>()>>;

class RandomizerBase : public IGodRandomizer
{
public:
    virtual ~RandomizerBase() = default;
    std::deque<God> randomizeGods() override;
protected:
    RandomizerBase(const RandomizeGods& p_phases);
    void changePhase(RandomizerPhase p_phase);

    Randomizer m_randomizer;
    RandomizerPhase m_state;
    RandomizeGods m_randomizeGods;

    std::deque<God> m_lastGodsSetting;
    std::deque<God> m_lastUnavailableGods;
};

class FivePlayersRandomizer : public RandomizerBase
{
public:
    FivePlayersRandomizer();
private:
    std::deque<God> randomize();
};

class FourPlayersRandomizer : public RandomizerBase
{
public:
    FourPlayersRandomizer();
private:
    std::deque<God> randomizeFirstPhase();
    std::deque<God> randomizeSecondPhase();
};

class ThreePlayersRandomizer : public RandomizerBase
{
public:
    ThreePlayersRandomizer();
private:
    std::deque<God> randomizeFirstPhase();
    std::deque<God> randomizeSecondPhase();

};
}
