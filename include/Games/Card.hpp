#pragma once

#include <iostream>
#include <string>
#include <array>
#include <cassert>

namespace pc {
namespace Games {

/// Class for representing cards in card games. 
class Card
{
public:
    /// NOTE: Ace is awlays regarded as ONE. If there are special cases, all of them must be handled manually
	enum class Value {Unknown, Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
	enum class Suit {Unknown, Heart, Diamond, Club, Spade};
	static constexpr std::array<Card::Suit, 4> commonSuits = {Card::Suit::Heart, Card::Suit::Club, Card::Suit::Diamond, Card::Suit::Spade};
    static constexpr std::array<Card::Value, 13> commonValues = {Card::Value::Ace, Card::Value::Two, Card::Value::Three, Card::Value::Four, Card::Value::Five, Card::Value::Six, Card::Value::Seven, Card::Value::Eight, Card::Value::Nine, Card::Value::Ten, Card::Value::Jack, Card::Value::Queen, Card::Value::King};

	/// create a legitimate card with passed Value and Suit
	Card(Value v, Suit s) noexcept;

	/// create a card with passing characters as input, first value then suit
	Card(char v, char s) noexcept;

	/// create a card with string with only 2 characteres, the first character will be trated as value, the second one as the suit
	Card(const std::string& s) noexcept;

    /// returns the value of the card
	Value value() const noexcept;

    /// returns the suit of the card
	Suit suit() const noexcept;

    /// returns a string representation of the card
    std::string stringRepresentation() const noexcept;

	/// useful tools for created and trasnforming values and suits
	static Value valueWithChar(char c);
	static char charOfValue(Value v);
	static Suit suitWithChar(char c);
	static char charOfSuit(Suit s);
    short number() const noexcept;

private:
    void initNumber() noexcept;
	Value m_value;
	Suit m_suit;
    short m_number;  ///each card can correspond to a unique number from 0 to 51
};


std::ostream& operator << (std::ostream&, const Card::Value&);
std::ostream& operator << (std::ostream&, const Card::Suit&);


std::ostream& operator << (std::ostream&, const Card&);
std::istream& operator >> (std::istream&, Card&);

/// cards are comparable by their value ace being the smallest
bool operator < (const Card& l, const Card& r);
bool operator == (const Card& l, const Card& r);
bool operator != (const Card& l, const Card& r);

}
}

namespace pc {
namespace Games {

//inline constexpr std::array<Card::Suit, 4> Card::commonSuits;
//inline constexpr std::array<Card::Value, 13> Card::commonValues;

inline Card::Card(Card::Value v, Card::Suit s) noexcept : m_value(v)
                                                        , m_suit(s)
{
    initNumber();
}

inline Card::Card(char v, char s) noexcept : Card(Card::valueWithChar(v)
                                           , Card::suitWithChar(s))
{
    initNumber();
}

inline Card::Card(const std::string& s) noexcept : Card(s[0], s[1])
{
}

inline Card::Value Card::value() const noexcept 
{
    return m_value;
}

inline Card::Suit Card::suit() const noexcept 
{
    return m_suit;
}

inline std::string Card::stringRepresentation() const noexcept 
{
    std::string r;
    r.push_back(charOfValue(m_value));
    r.push_back(charOfSuit(m_suit));
    return r;  
}

inline Card::Value Card::valueWithChar(char c) 
{
    switch(c) {
        case 'A':
            return Value::Ace;
        case '2':
            return Value::Two;
        case '3':
            return Value::Three;
        case '4':
            return Value::Four;
        case '5':
            return Value::Five;
        case '6':
            return Value::Six;
        case '7':
            return Value::Seven;
        case '8':
            return Value::Eight;
        case '9':
            return Value::Nine;
        case 'T':
            return Value::Ten;
        case 'J':
            return Value::Jack;
        case 'Q':
            return Value::Queen;
        case 'K':
            return Value::King;
        default:
            return Value::Unknown;
    }
    return Value::Unknown;
}

inline char Card::charOfValue(Card::Value v)
{
    switch(v) {
        case Value::Ace:
            return 'A';
        case Value::Two:
            return '2';
        case Value::Three:
            return '3';
        case Value::Four:
            return '4';
        case Value::Five:
            return '5';
        case Value::Six:
            return '6';
        case Value::Seven:
            return '7';
        case Value::Eight:
            return '8';
        case Value::Nine:
            return '9';
        case Value::Ten:
            return 'T';
        case Value::Jack:
            return 'J';
        case Value::Queen:
            return 'Q';
        case Value::King:
            return 'K';
        default:
            return 'U';
    }
    return 'U';
}

inline Card::Suit Card::suitWithChar(char c)
{
    switch(c) {
        case 'H':
            return Suit::Heart;
        case 'D':
            return Suit::Diamond;
        case 'C':
            return Suit::Club;
        case 'S':
            return Suit::Spade;
        default:
            return Suit::Unknown;
    }
    return Suit::Unknown;
}

inline char Card::charOfSuit(Suit s)
{
    switch (s) {
        case Suit::Heart:
            return 'H';
        case Suit::Diamond:
            return 'D';
        case Suit::Club:
            return 'C';
        case Suit::Spade:
            return 'S';
        default:
            return 'U';
    }
    return 'U';
}

inline short Card::number() const noexcept  
{
    return m_number;
}

inline void Card::initNumber() noexcept 
{   
    m_number = (static_cast<int>(m_value) - 1) * 4 + static_cast<int>(m_suit) - 1; 
}

inline std::ostream& operator << (std::ostream& out, const Card::Value& v)
{
    out << Card::charOfValue(v);
    return out;
}

inline std::ostream& operator << (std::ostream& out, const Card::Suit& s)
{
    out << Card::charOfSuit(s);
    return out;
}

inline std::ostream& operator << (std::ostream& out, const Card& c)
{
    out << c.value() << c.suit();
    return out;
}

inline std::istream& operator >> (std::istream& in, Card& c)
{
    std::string s;
    in >> s;
    assert( s.size() >=2 && s.size() <=3 );
    c = Card(s);
    return in;
}

inline bool operator < (const Card& l, const Card& r)
{
    int li = static_cast<int>(l.value());
    int ri = static_cast<int>(r.value());
    if (li != ri) {
        return li < ri;
    }
    return static_cast<int>(l.suit()) < static_cast<int>(r.suit());
}

inline bool operator == (const Card& l, const Card& r)
{
    return l.value() == r.value() && l.suit() == r.suit();
}

inline bool operator != (const Card& l, const Card& r)
{
    return !(l == r);
}


}
}
