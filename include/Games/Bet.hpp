#pragma once

#include <string>
#include <functional>

namespace pc {
namespace Games {

/// Generic bet class, is dependant on the State type S.
template<typename S>
class Bet
{
public:
    /**
     * @brief Construct a bet object. 
     * @param name slug for the bet
     * @param checker a checker function that returns true if the bet succeed for the given state S
     * @param coef The winning coefficient of this bet
     **/ 
    Bet(const std::string& name, std::function<bool(S)> checker, float coef);

    /// check if the current bet won for the given state
    bool check(const S&) const;

    std::string name() const;

    double coef() const;

private:
    std::string m_name;
    std::function<bool(S)> m_checker;
    double m_coef;
};
}  
}


#include "Games/Bet_impl.hpp"

