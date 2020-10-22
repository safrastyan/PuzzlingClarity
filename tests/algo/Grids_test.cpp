#define BOOST_TEST_MODULE Graphs
#include <boost/test/unit_test.hpp>

#include "algo/Grids.hpp"
#include "Comparators/Comparators.hpp"

using namespace pc::algo;
using namespace pc::Comparators;

BOOST_AUTO_TEST_SUITE(Graph_tests)


BOOST_AUTO_TEST_CASE(Grid_rotate_90_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });
    auto g1 = rotate_90_clockwise(g);

    BOOST_CHECK_EQUAL(g1[0][2], '1');
    BOOST_CHECK_EQUAL(g1[1][1], '5');
    BOOST_CHECK_EQUAL(g1[2][0], '9');
    

    auto g2 = rotate_90_clockwise(rotate_90_clockwise(rotate_90_clockwise(rotate_90_clockwise(g))));
    BOOST_CHECK(is_same(g2, g));
    BOOST_CHECK(!is_same(rotate_90_clockwise(g2),  g));
}

BOOST_AUTO_TEST_CASE(Grid_rotate_180_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = rotate_180_clockwise(g);

    Grid correct(std::vector<std::vector<char>>{ {'9', '8', '7'}, 
                                                 {'6', '5', '4'} , 
                                                 {'3', '2', '1'}  });

    BOOST_CHECK(is_same(g1, correct));
}

BOOST_AUTO_TEST_CASE(Grid_rotate_270_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = rotate_270_clockwise(g);

    Grid correct(std::vector<std::vector<char>>{ {'3', '6', '9'}, 
                                                 {'2', '5', '8'} , 
                                                 {'1', '4', '7'}  });

    BOOST_CHECK(is_same(g1, correct));

}

BOOST_AUTO_TEST_CASE(Grid_mirror_horizontal)
{
    Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = mirror_horizontal(g);
    
    Grid correct(std::vector<std::vector<char>>{ {'3', '2', '1'}, 
                                                 {'6', '5', '4'} , 
                                                 {'9', '8', '7'}  });

    BOOST_CHECK(is_same(g1, correct));

}

BOOST_AUTO_TEST_CASE(Grid_connected_component)
{

}

BOOST_AUTO_TEST_CASE(Grid_fill_connected_component)
{
    
}

BOOST_AUTO_TEST_CASE(Grid_fill)
{
    
}

BOOST_AUTO_TEST_SUITE_END()
