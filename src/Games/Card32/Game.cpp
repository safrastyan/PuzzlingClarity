#include "Games/Card32/Game.hpp"
#include "Games/Deck.hpp"

#include <iostream>
#include <algorithm>

namespace {

/// get the indices of maximums
std::vector<int> winnig_indices(const std::vector<int>& data)
{
    auto m = *std::max_element(data.begin(), data.end());
    std::vector<int> res;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == m) {
            res.push_back(i);
        }
    }
    return res;
}

}

namespace pc {
namespace Games {
namespace Card32 {

Game::State Game::play(bool debug)
{

    Deck d(Deck::Type::Card32);
    d.shuffle();
    

    std::vector<int> all{8, 9, 10, 11};

    /// draw once for all
    for (int i = 0; i < all.size(); ++i) {
        auto draw = d.takeTop();
        all[i] += static_cast<int>(draw.value());
    }
    while (true) {
        auto indices = winnig_indices(all);
        if (indices.size() == 1) {
            return State(index_to_win(indices[0]), all);
        }
        /// draw for winners only
        for (auto i: indices) {
            auto draw = d.takeTop();
            all[i] += static_cast<int>(draw.value());
        }
    }

}

Game::Win Game::index_to_win(int i)
{
    switch (i) {
    case 0:
        return Win::Eight;
    case 1:
        return Win::Nine;
    case 2:
        return Win::Ten;
    default:
        return Win::Eleven;
    }
}

}
}
}
