#define BOOST_TEST_MODULE Card_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/AndharBahar/Game.hpp"

using namespace pc::Games::AndharBahar;

BOOST_AUTO_TEST_SUITE(AndharBahar_test)

BOOST_AUTO_TEST_CASE(flow_test)
{
    ///TODO poor test
    Game g;
    auto res = g.play(true);
    std::cout << "Reuslts " << std::endl;
    std::cout << "Winner " <<  (res.winner == Game::Win::Andhar ? "Andhar " : "Bahar") << " " << res.card_num << std::endl;
}


BOOST_AUTO_TEST_SUITE_END()
