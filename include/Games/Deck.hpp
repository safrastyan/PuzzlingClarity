#pragma once

#include "Games/Card.hpp"

#include <vector>
#include <array>
#include <algorithm>
#include <random>

namespace pc {
namespace Games {

/// Deck is always treated as standartized deck where all cards are faceDown and the top card is the topmost face down card
class Deck
{
public:
    /// Standard is a 52 card deck, Double is double 52 cards deck, Small is 36 card deck
    enum class Type : char { Small, Standard, Double };
    Deck(Type t = Type::Standard);

    /// read only, returns the top card
    Card top() const;

    /// returns the top card and throws it away
    Card takeTop();

    /// shuffle the deck
    void shuffle();

    /// add a card on top
    void add(const Card&);

    /// number of cards in the deck
    int size() const;

    /// constant getter with index
    Card at(int) const;

    /// sprting based on Card's comparator
    void sort();

    /// discards the passed card from the deck
    void discard(const Card&);

private:
    void initializeStandard();
    void initializeSmall();
    void initializeDouble();

    /// vector keeps the cards bottom up, first card is the bottom most and the last card is the topmost
    std::vector<Card> m_cards;
};

std::ostream& operator << (std::ostream&, const Deck&);

}
}

namespace pc {
namespace Games {

inline Deck::Deck(Type t)
{
    switch(t) {
    case Type::Standard:
        initializeStandard();
        break;
    case Type::Small:
        initializeSmall();
        break;
    case Type::Double:
        initializeDouble();
        break;
    }
}

inline Card Deck::top() const
{
    return m_cards.back();
}

inline Card Deck::takeTop()
{
    auto c = m_cards.back();
    m_cards.pop_back();
    return c;
}

inline void Deck::shuffle()
{
    std::random_device random_dev;
    std::mt19937 generator(random_dev());
    std::shuffle(m_cards.begin(), m_cards.end(), generator);
}

inline void Deck::add(const Card& c)
{
    m_cards.push_back(c);
}

inline int Deck::size() const
{
    return m_cards.size();
}

inline Card Deck::at(int i) const
{
    return m_cards[i];
}

inline void Deck::sort()
{
    std::sort(m_cards.begin(), m_cards.end());
}

inline void Deck::discard(const Card& c)
{
    auto f = std::find(m_cards.begin(), m_cards.end(), c);
    if (f == m_cards.end()) {
        return;
    }
    m_cards.erase(f);
}


inline void Deck::initializeStandard()
{
    for (auto s : Card::commonSuits) {
        for (int i = 1; i <= 13; ++i) {
            m_cards.push_back(Card(static_cast<Card::Value>(i), s));
        }
    }
}

inline void Deck::initializeSmall()
{
    for (auto s : Card::commonSuits) {
        for (int i = 6; i <= 13; ++i) {
            m_cards.push_back(Card(static_cast<Card::Value>(i), s));
        }
    }
}

inline void Deck::initializeDouble()
{
    initializeStandard();
    initializeStandard();
}

inline std::ostream& operator << (std::ostream& out, const Deck& h)
{
    for (int i = 0; i < h.size(); ++i) {
        std::cout << h.at(i) << " ";
    }
    return out;
}


}
}
