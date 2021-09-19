#include "Games/AndharBahar/Game.hpp"
#include "Games/Deck.hpp"

#include <iostream>

namespace pc {
namespace Games {
namespace AndharBahar {

Game::State Game::play(bool debug)
{

    Deck d;
    d.shuffle();
    auto joker = d.takeTop();

    if (debug) {
        std::cout << "Joker is " << joker << std::endl;
    }
    m_andhar.clear();
    m_bahar.clear();    
    int c = 0;

    while (true) {
        auto card = d.takeTop();
        if (debug) {
            std::cout << "Drew card " << card << std::endl;
        }
        ++c;
        if (card.value() == joker.value()) {
            return State( (bahar() ? Win::Bahar : Win::Andhar), c);
        }
        if (bahar()) {
            m_bahar.push_back(card);
        } else { 
            m_andhar.push_back(card);
        }

        if (!debug) {
            continue;
        }
        std::cout << std::endl;
        std::cout << "Andhar" << std::endl;
        for (const auto& c: m_andhar) {
            std::cout << c << " ";
        }
        std::cout << std::endl;

        std::cout << "Bahar" << std::endl;
        for (const auto& c: m_bahar) {
            std::cout << c << " ";
        }
        std::cout << std::endl << std::endl;;
    }
}

bool Game::bahar() const
{
    return m_andhar.size() == m_bahar.size();
}


}
}
}
