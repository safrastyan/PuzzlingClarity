#pragma once

#include "Games/Card.hpp"

#include <vector>

namespace pc {
namespace Games {
namespace Card32 {

class Game
{
public:

    enum class Win : char 
    {
       Eight = 1, 
       Nine = 2, 
       Ten = 3, 
       Eleven = 4
    };

    struct State 
    {
        State(Win w, const std::vector<int>& all): winner(w)
                                           , all(all)
        {}   
        Win winner;
        std::vector<int> all;
    };
    
    Game() = default;
    
    /// returns a pair. the winning type and the number of cards drawn
    State play(bool debug = false);
private:

    static Win index_to_win(int);
};


}
}
}
