#define BOOST_TEST_MODULE Deck_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/Deck.hpp"

using namespace pc::Games;

BOOST_AUTO_TEST_SUITE(Deck_test)

BOOST_AUTO_TEST_CASE(Size_test)
{
    Deck d;
    BOOST_CHECK_EQUAL(d.size(), 52);
    Deck dd(Deck::Type::Double);
    BOOST_CHECK_EQUAL(dd.size(), 104);
    auto c = d.takeTop();
    BOOST_CHECK_EQUAL(d.size(), 51);
    d.add(c);
    BOOST_CHECK_EQUAL(d.size(), 52);

    Deck ddd(Deck::Type::Small);
    BOOST_CHECK_EQUAL(ddd.size(), 36);

    ddd = Deck(Deck::Type::Card32);
    BOOST_CHECK_EQUAL(ddd.size(), 32);

}

BOOST_AUTO_TEST_CASE(discard)
{
    Deck d;
    Card c('A', 'S');
    d.discard(c);
    BOOST_CHECK_EQUAL(d.size(), 51);
    auto f = std::find(d.m_cards.begin(), d.m_cards.end(), c);
    BOOST_CHECK(f == d.m_cards.end());
}
BOOST_AUTO_TEST_SUITE_END()
