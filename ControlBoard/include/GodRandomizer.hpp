#pragma once

#include <random>
#include <memory>

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

class ThreePlayersRandomizer;
class IRandomizerPhase
{
public:
    virtual std::deque<God> randomizeGods(ThreePlayersRandomizer* p_randomizer) = 0;
    void changePhase(ThreePlayersRandomizer* p_randomizer, std::shared_ptr<IRandomizerPhase> p_phase);
};

class FirstPhase : public IRandomizerPhase
{
public:
    static std::shared_ptr<IRandomizerPhase> instance();
    std::deque<God> randomizeGods(ThreePlayersRandomizer* p_randomizer) override;
private:
    static std::shared_ptr<IRandomizerPhase> m_instance;
};

class SecondPhase : public IRandomizerPhase
{
public:
    static std::shared_ptr<IRandomizerPhase> instance();
    std::deque<God> randomizeGods(ThreePlayersRandomizer* p_randomizer) override;
private:
    static std::shared_ptr<IRandomizerPhase> m_instance;
};

class ThreePlayersRandomizer : public RandomizerBase
{
public:
    ThreePlayersRandomizer();
    std::deque<God> randomizeGods() override;
private:
    friend class IRandomizerPhase;
    void changePhase(std::shared_ptr<IRandomizerPhase> p_phase);

    std::shared_ptr<IRandomizerPhase> m_state;
    std::deque<God> m_lastUnavailableGods;
};

}
