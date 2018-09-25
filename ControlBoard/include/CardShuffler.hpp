#pragma once

#include <random>
#include <algorithm>
#include <deque>

namespace Cyclades
{
class CardShuffler
{
public:
    CardShuffler() : m_seed(m_random()) {}

    template<typename T>
    void shuffle(std::deque<T>& p_dequeToShuffle)
    {
        std::shuffle(p_dequeToShuffle.begin(), p_dequeToShuffle.end(), m_seed);
    }

private:
    std::random_device m_random;
    std::mt19937 m_seed;
};

}
