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

enum class Creature
{
    Chimera,
    Chrion,
    Cyclops,
    Dryad,
    Giant,
    Griffin,
    Harpy,
    Kraken,
    Medusa,
    Minotaur,
    Moirai,
    Pegasus,
    Polyphemus,
    Satire,
    Siren,
    Sphinx,
    Sylphide
};

const std::vector<Creature> ALL_CREATURES { Creature::Chimera,
                                            Creature::Chrion,
                                            Creature::Cyclops,
                                            Creature::Dryad,
                                            Creature::Giant,
                                            Creature::Griffin,
                                            Creature::Harpy,
                                            Creature::Kraken,
                                            Creature::Medusa,
                                            Creature::Minotaur,
                                            Creature::Moirai,
                                            Creature::Pegasus,
                                            Creature::Polyphemus,
                                            Creature::Satire,
                                            Creature::Siren,
                                            Creature::Sphinx,
                                            Creature::Sylphide };

inline std::ostream& operator <<(std::ostream& os, Creature p_creatureToPrint)
{
    switch(p_creatureToPrint)
    {
    case Creature::Chimera:
        return os << "Chimera";
    case Creature::Chrion:
        return os << "Chrion";
    case Creature::Cyclops:
        return os << "Cyclops";
    case Creature::Dryad:
        return os << "Dryad";
    case Creature::Giant:
        return os << "Giant";
    case Creature::Griffin:
        return os << "Griffin";
    case Creature::Harpy:
        return os << "Harpy";
    case Creature::Kraken:
        return os << "Kraken";
    case Creature::Medusa:
        return os << "Medusa";
    case Creature::Minotaur:
        return os << "Minotaur";
    case Creature::Moirai:
        return os << "Moirai";
    case Creature::Pegasus:
        return os << "Pegasus";
    case Creature::Polyphemus:
        return os << "Polyphemus";
    case Creature::Satire:
        return os << "Satire";
    case Creature::Siren:
        return os << "Siren";
    case Creature::Sphinx:
        return os << "Sphinx";
    case Creature::Sylphide:
        return os << "Sylphide";
    default:
        return os << "Invalid Creature!";
    }
}


}
