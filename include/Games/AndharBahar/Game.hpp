#pragma once

#include "Games/Card.hpp"

#include <vector>

namespace pc {
namespace Games {
namespace AndharBahar {

class Game
{
public:

    enum class Win : char 
    {
        Andhar = 1, 
        Bahar = 2
    };

    struct State 
    {
        State(Win w, int num): winner(w)
                             , card_num(num)
        {}   
        Win winner;
        int card_num;
    };
    
    Game() = default;
    
    /// returns a pair. the winning type and the number of cards drawn
    State play(bool debug = false);
    bool bahar() const; /// returns whether its bahar's turn

private:
    std::vector<Card> m_andhar;
    std::vector<Card> m_bahar;
};


}
}
}
