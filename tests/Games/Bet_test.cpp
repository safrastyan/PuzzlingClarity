#define BOOST_TEST_MODULE Bet_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/Bet.hpp"

using namespace pc::Games;


struct TestState
{
    int winner;
    std::string meta;
};

bool winner_1(const TestState& s)
{
    return s.winner == 1;
}

bool winner_2(const TestState& s)
{
    return s.winner == 2;
}

BOOST_AUTO_TEST_SUITE(Bet_test)

BOOST_AUTO_TEST_CASE(TestState_Bet_test)
{
    Bet<TestState> b1("b1", winner_1, 1.2);
    Bet<TestState> b2("b2", winner_2, 1.3);

    TestState s1;
    s1.winner = 1;

    TestState s2;
    s2.winner = 2;

    TestState s3;
    s3.winner = 3;

    BOOST_CHECK(b1.check(s1));
    BOOST_CHECK(!b1.check(s2));

    BOOST_CHECK(b2.check(s2));
    BOOST_CHECK(!b2.check(s1));

    BOOST_CHECK(!b1.check(s3));
    BOOST_CHECK(!b2.check(s3));
}


BOOST_AUTO_TEST_SUITE_END()
