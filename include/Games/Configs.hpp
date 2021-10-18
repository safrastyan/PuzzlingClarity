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