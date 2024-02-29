#define BOOST_TEST_MODULE Grids
#include <boost/test/unit_test.hpp>

#include "algo/Grids.hpp"
#include "Comparators/Comparators.hpp"

using namespace pc::algo;
using namespace pc::Comparators;

BOOST_AUTO_TEST_SUITE(Grids_tests)


BOOST_AUTO_TEST_CASE(Grid_equality_check_check)
{
    Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                         {'4', '5', '6'} , 
                                         {'7', '8', '9'}  });
    auto g2 = g;
    BOOST_CHECK(g == g2);
    g[0][0] = 'x';
    BOOST_CHECK(!(g == g2));
    g[0][0] = '1';
    g[1].pop_back();
    BOOST_CHECK(!(g == g2));
}
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
    Grid g(std::vector<std::vector<char>>{ {'2', '2', '2'}, 
                                                 {'6', '2', '4'} , 
                                                 {'9', '2', '7'}  });
    auto c = connected_component(g, 0, 0);
    BOOST_CHECK_EQUAL(c.size(), 5);
    BOOST_CHECK(std::find(c.begin(), c.end(), std::make_pair(0, 0)) != c.end());
    BOOST_CHECK(std::find(c.begin(), c.end(), std::make_pair(0, 1)) != c.end());
    BOOST_CHECK(std::find(c.begin(), c.end(), std::make_pair(1, 1)) != c.end());
    BOOST_CHECK(std::find(c.begin(), c.end(), std::make_pair(0, 2)) != c.end());
    BOOST_CHECK(std::find(c.begin(), c.end(), std::make_pair(2, 1)) != c.end());   

}   

BOOST_AUTO_TEST_CASE(Grid_fill_connected_component)
{
    Grid g(std::vector<std::vector<char>>{ {'2', '2', '2'}, 
                                             {'6', '2', '4'} , 
                                             {'9', '2', '7'}  });  

    Grid cor(std::vector<std::vector<char>>{ {'x', 'x', 'x'}, 
                                             {'6', 'x', '4'} , 
                                             {'9', 'x', '7'}  });  
    fill_connected_component(g, 0, 0, 'x');
    BOOST_CHECK(g == cor);
    ///TODO add tests for the generic one as well
}


BOOST_AUTO_TEST_SUITE_END()
