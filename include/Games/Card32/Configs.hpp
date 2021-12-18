#pragma once
/// This file contains configurations for various games


#include "Games/Bet.hpp"

#include "Games/Card32/Game.hpp"

namespace pc {
namespace Games {
namespace Configs {

std::pair<Card32::Game, std::vector<Bet<Card32::Game::State>>> lottoland_32_card_live();

}
}
}


namespace pc {
namespace Games {
namespace Configs {

std::pair<Card32::Game, std::vector<Bet<Card32::Game::State>>> lottoland_32_card_live()
{
    Card32::Game g;
    std::vector<Bet<Card32::Game::State>> bets;

    bets.emplace_back("8 wins", [](const auto& s) {return s.winner == Card32::Game::Win::Eight;} , 11);
    bets.emplace_back("9 wins", [](const auto& s) {return s.winner == Card32::Game::Win::Nine;} , 4.5);
    bets.emplace_back("10 wins", [](const auto& s) {return s.winner == Card32::Game::Win::Ten;} , 2.2);
    bets.emplace_back("11 wins", [](const auto& s) {return s.winner == Card32::Game::Win::Eleven;} , 1);

    return std::make_pair(g, bets);
}


}
}
}