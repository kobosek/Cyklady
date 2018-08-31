#pragma once

#include <random>
#include <algorithm>
#include "Types.hpp"

namespace Cyclades
{
class Randomizer
{
public:
    Randomizer() : m_seed(m_random()) {}

    template<typename T>
    void randomize(std::vector<T>& p_typeVector)
    {
        std::shuffle(p_typeVector.begin(), p_typeVector.end(), m_seed);
    }

private:
    std::random_device m_random;
    std::mt19937 m_seed;
};

}
