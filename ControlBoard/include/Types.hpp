#pragma once
#include <vector>
#include <ostream>

namespace Cyclades
{

enum class NumberOfPlayers
{
    Five,
    Four,
    Three,
    Two
};

enum class God
{
    Aphrodite,
    Ares,
    Poseidon,
    Zeus,
    Empty
};

const std::vector<God> ALL_GODS { God::Aphrodite,
                                  God::Ares,
                                  God::Poseidon,
                                  God::Zeus };

inline std::ostream& operator <<(std::ostream& os, God p_godToPrint)
{
    switch(p_godToPrint)
    {
    case God::Aphrodite:
        return os << "Aphrodite";
    case God::Ares:
        return os << "Ares";
    case God::Poseidon:
        return os << "Poseidon";
    case God::Zeus:
        return os << "Zeus";
    default:
        return os << "Empty";
    }
}

enum class Color
{
    Blue,
    Black,
    Green,
    Red,
    Yellow
};

inline std::ostream& operator <<(std::ostream& os, Color p_colorToPrint)
{
    switch(p_colorToPrint)
    {
    case Color::Blue:
        return os << "Blue";
    case Color::Black:
        return os << "Black";
    case Color::Green:
        return os << "Green";
    case Color::Red:
        return os << "Red";
    case Color::Yellow:
        return os << "Yellow";
    default:
        return os << "Inalid Color!";
    }
}

enum class Beast
{

};

const std::vector<Beast> ALL_BEASTS { };

inline std::ostream& operator <<(std::ostream& os, Beast p_beastToPrint)
{
    switch(p_beastToPrint)
    {
    default:
        return os << "Invalid Beast!";
    }
}


}
