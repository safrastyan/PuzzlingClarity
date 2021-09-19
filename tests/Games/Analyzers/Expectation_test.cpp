#define BOOST_TEST_MODULE Expectation_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/Analyzers/Expectation.hpp"
#include "Comparators/Comparators.hpp"

using namespace pc::Games::Analyzers;
using pc::Games::Bet;
using pc::Comparators::same_double;

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

bool winner_3(const TestState& s)
{
    return s.winner == 3;
}

/// this test assumes that we have a game in which the 1 wins exactly 50% of the time, 2 - 40% and 3 - 10%
/// Correspondingly the coeficient for the 1 will be 2.1, for 2 will be 2.5 and for 3 will be 9. So the best bet should be the first. 

BOOST_AUTO_TEST_SUITE(Expectation_test)

BOOST_AUTO_TEST_CASE(Analyze_expectations_test)
{
    std::vector<TestState> states;

    std::vector<Bet<TestState>> bets;
    bets.emplace_back("win1", winner_1, 2.1);
    bets.emplace_back("win2", winner_2, 2.5);
    bets.emplace_back("win3", winner_3, 9);

    for (int i = 0; i < 500; ++i) {
        TestState s;
        s.winner = 1;
        states.push_back(s);
    }

    for (int i = 0; i < 400; ++i) {
        TestState s;
        s.winner = 2;
        states.push_back(s);
    }

    for (int i = 0; i < 100; ++i) {
        TestState s;
        s.winner = 3;
        states.push_back(s);
    }

    Expectation<TestState> e(states, bets);

    auto all = e.calc_all();

    for (const auto& a: all) {
        if (a.first.name() == "win1") {
            BOOST_CHECK(same_double(a.second, 1.05));
            continue;
        }
        if (a.first.name() == "win2") {
            BOOST_CHECK(same_double(a.second, 1));
            continue;
        }
        BOOST_CHECK(same_double(a.second, 0.9));        
    }


    auto b = e.best_bet();
    BOOST_CHECK_EQUAL(b.first.name(), "win1");
    BOOST_CHECK(same_double(b.second, 1.05));
    

}


BOOST_AUTO_TEST_SUITE_END()
