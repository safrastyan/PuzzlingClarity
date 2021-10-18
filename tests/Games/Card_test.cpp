#define BOOST_TEST_MODULE Card_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/Card.hpp"

using namespace pc::Games;

BOOST_AUTO_TEST_SUITE(Card_test)

BOOST_AUTO_TEST_CASE(Basic_test)
{
    std::cout << "common suits for card are " << std::endl;
    for (auto s : Card::commonSuits) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << "common values for cards are " << std::endl;
    for (auto v : Card::commonValues) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    BOOST_CHECK_EQUAL(Card::commonValues.size(), 13);

    BOOST_CHECK_EQUAL(Card("AH").number(), 0);
    BOOST_CHECK_EQUAL(Card("AS").number(), 3);
    BOOST_CHECK_EQUAL(Card("KS").number(), 51);

}

BOOST_AUTO_TEST_CASE(Constructors)
{
    auto vv = Card::commonValues;
    auto ss = Card::commonSuits;
    for (auto v : vv) {
        BOOST_CHECK_EQUAL(v, Card::valueWithChar(Card::charOfValue(v)));
    }

    for (auto s : ss) {
        BOOST_CHECK_EQUAL(s, Card::suitWithChar(Card::charOfSuit(s)));
    }

    for (auto v : vv) {
        for (auto s : ss) {
            Card c1(v, s);
            Card c2(Card::charOfValue(v), Card::charOfSuit(s));
            std::string c3_desc;
            c3_desc += Card::charOfValue(v);
            c3_desc += Card::charOfSuit(s);
            Card c3(c3_desc);
            BOOST_CHECK_EQUAL(c1, c2);
            BOOST_CHECK_EQUAL(c1, c3);
            BOOST_CHECK_EQUAL(c2, c3);
        }
    }
}

BOOST_AUTO_TEST_CASE(Comparing)
{
    auto vv = Card::commonValues;
    auto ss = Card::commonSuits;
    for (int i = 0; i < vv.size() - 1; ++i) {
        for (auto s1 : ss) {
            Card c1(static_cast<Card::Value>(i + 1), s1);
            for (int j = i + 1;j < vv.size(); ++j) {
                for (auto s2 : ss) {
                    Card c2(static_cast<Card::Value>(j + 1), s2);
                    BOOST_CHECK(c1 < c2);
                }
            }
        }
    }
}

BOOST_AUTO_TEST_CASE(string_representation)
{
    Card c("AH");
    BOOST_CHECK_EQUAL(std::string("AH"), c.stringRepresentation());
}

BOOST_AUTO_TEST_SUITE_END()
