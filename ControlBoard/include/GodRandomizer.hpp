#pragma once

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

using RandomizeGods = std::map<RandomizerPhase, std::function<void()>>;

class RandomizerBase : public IGodRandomizer
{
public:
    virtual ~RandomizerBase() = default;
    std::deque<God> randomizeGods() override;
protected:
    RandomizerBase(const RandomizeGods& p_phases);
    void changePhase(RandomizerPhase p_phase);
    void commonRandomize(const int p_numberOfUnavailableGods);

    RandomizerPhase m_state;
    RandomizeGods m_randomizeGods;

    std::deque<God> m_lastAvailableGods;
    std::deque<God> m_lastUnavailableGods;

    Randomizer m_randomizer;

};

class FivePlayersRandomizer : public RandomizerBase
{
public:
    FivePlayersRandomizer();
private:
    void randomize();
};

class FourPlayersRandomizer : public RandomizerBase
{
public:
    FourPlayersRandomizer();
private:
    void randomize();
};

class ThreePlayersRandomizer : public RandomizerBase
{
public:
    ThreePlayersRandomizer();
private:
    void randomizeFirstPhase();
    void randomizeSecondPhase();
    void resetGods();

};
}
