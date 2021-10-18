#pragma once

#include <vector>

#include "Games/Bet.hpp"

namespace pc {
namespace Games {
namespace Analyzers {

/// Class for calculating the expectations of various bets based on the history of occurances of outcomes. Depends on the state parameter
template<typename S>
class Expectation 
{
public:
    /// Receives the state history and the bets for checking
    Expectation(const std::vector<S>& data, const std::vector<Bet<S>>& bets);

    /// Calculate for all bets their return expectations and return in a vector pair, first element the bet, second is the expectation
    std::vector<std::pair<Bet<S>, double>> calc_all() const;

    /// returns the best bet by expectaion
    std::pair<Bet<S>, double> best_bet() const;

private:
    std::vector<S> m_states;
    std::vector<Bet<S>> m_bets;
};


}
}
}

#include "Games/Analyzers/Expectation_impl.hpp"
