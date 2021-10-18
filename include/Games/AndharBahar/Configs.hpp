#pragma once
/// This file contains configurations for various games


#include "Games/Bet.hpp"

#include "Games/AndharBahar/Game.hpp"

namespace pc {
namespace Games {
namespace Configs {

std::pair<AndharBahar::Game, std::vector<Bet<AndharBahar::Game::State>>> lottoland_andhar_bahar();

}
}
}


namespace pc {
namespace Games {
namespace Configs {

std::pair<AndharBahar::Game, std::vector<Bet<AndharBahar::Game::State>>> lottoland_andhar_bahar()
{
    AndharBahar::Game g;
    std::vector<Bet<AndharBahar::Game::State>> bets;


    bets.emplace_back("andhar_wins", [](const auto& s) {return s.winner == AndharBahar::Game::Win::Andhar;} , 2);
    bets.emplace_back("bahar_wins", [](const auto& s) {return s.winner == AndharBahar::Game::Win::Bahar;} , 1.9);

    bets.emplace_back("1-5", [](const auto& s) {return s.card_num >= 1 && s.card_num <= 5;} , 3.5);
    bets.emplace_back("6-10", [](const auto& s) {return s.card_num >= 6 && s.card_num <= 10;} , 4.5);
    bets.emplace_back("11-15", [](const auto& s) {return s.card_num >= 11 && s.card_num <= 15;} , 5.5);
    bets.emplace_back("16-25", [](const auto& s) {return s.card_num >= 16 && s.card_num <= 25;} , 4.5);
    bets.emplace_back("26-30", [](const auto& s) {return s.card_num >= 26 && s.card_num <= 30;} , 15);
    bets.emplace_back("31-35", [](const auto& s) {return s.card_num >= 31 && s.card_num <= 35;} , 25);
    bets.emplace_back("36-40", [](const auto& s) {return s.card_num >= 36 && s.card_num <= 40;} , 50);
    bets.emplace_back("More than 40", [](const auto& s) {return s.card_num >= 41;} , 102);

    return std::make_pair(g, bets);
}


}
}
}