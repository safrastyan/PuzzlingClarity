#include "Games/Collector.hpp"
#include "Games/Configs.hpp"
#include "Games/Analyzers/Expectation.hpp"

#include <iostream>

using namespace pc::Games::Card32;
using namespace pc::Games;

int main(int argc, char** argv)
{
    int n = std::stoi(argv[1]);
    std::cout << "Running Lottoland Card 32 live on " << n << " games... " << std::endl;

    auto [g, bets] = Configs::lottoland_32_card_live();
    
    auto states = collect<decltype(g)>(g, n);

    Analyzers::Expectation<decltype(g)::State> e(states, bets);
    auto res = e.calc_all();

    for (const auto& r: res) {
        std::cout << "Bet " << r.first.name() << " rtp is " << r.second << std::endl;
    }
   
    return 0;
}