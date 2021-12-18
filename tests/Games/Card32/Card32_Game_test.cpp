#define BOOST_TEST_MODULE Card_test
#include <boost/test/unit_test.hpp>

#define private public
#include "Games/Card32/Game.hpp"

using namespace pc::Games::Card32;

BOOST_AUTO_TEST_SUITE(Card32_test)

BOOST_AUTO_TEST_CASE(flow_test)
{
    ////TODO poor test
    Game g;
    auto res = g.play(true);
    std::cout << "Reuslts " << std::endl;
    std::cout << static_cast<int>(res.winner) << std::endl;
}


BOOST_AUTO_TEST_SUITE_END()
