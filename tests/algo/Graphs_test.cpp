#define BOOST_TEST_MODULE Graphs
#include <boost/test/unit_test.hpp>

#include "algo/Graphs.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(Graph_tests)

BOOST_AUTO_TEST_CASE(equality_grid)
{
    Grid g1(3, 4);
    Grid g2(3, 3);

    BOOST_CHECK(!(g1 == g2));

    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });

    g2 = g;
    BOOST_CHECK(g2 == g);
    g2.data[2][2] = 'a';
    BOOST_CHECK(!(g2 == g));
}

BOOST_AUTO_TEST_CASE(Grid_constructors)
{
    const Grid g(3, 3, 'a');
    const Grid gg(std::vector<std::vector<char>>{ {'a', 'a', 'a'}, 
                                                 {'a', 'a', 'a'} , 
                                                 {'a', 'a', 'a'}  });
    BOOST_CHECK(g == gg);
}

BOOST_AUTO_TEST_CASE(Grid_rotate_90_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });
    auto g1 = g.rotate_90_clockwise();

    BOOST_CHECK_EQUAL(g1.data[0][2], '1');
    BOOST_CHECK_EQUAL(g1.data[1][1], '5');
    BOOST_CHECK_EQUAL(g1.data[2][0], '9');
    

    auto g2 = g.rotate_90_clockwise().rotate_90_clockwise().rotate_90_clockwise().rotate_90_clockwise();
    BOOST_CHECK(g2 == g);

    BOOST_CHECK(!(g2.rotate_90_clockwise() == g));
}

BOOST_AUTO_TEST_CASE(Grid_rotate_180_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = g.rotate_180_clockwise();

    Grid correct(std::vector<std::vector<char>>{ {'9', '8', '7'}, 
                                                 {'6', '5', '4'} , 
                                                 {'3', '2', '1'}  });

    BOOST_CHECK(g1 == correct);

}

BOOST_AUTO_TEST_CASE(Grid_rotate_270_clockwise)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = g.rotate_270_clockwise();

    Grid correct(std::vector<std::vector<char>>{ {'3', '6', '9'}, 
                                                 {'2', '5', '8'} , 
                                                 {'1', '4', '7'}  });

    BOOST_CHECK(g1 == correct);

}

BOOST_AUTO_TEST_CASE(Grid_mirror_horizontal)
{
    const Grid g(std::vector<std::vector<char>>{ {'1', '2', '3'}, 
                                                 {'4', '5', '6'} , 
                                                 {'7', '8', '9'}  });


    auto g1 = g.mirror_horizontal();
    
    Grid correct(std::vector<std::vector<char>>{ {'3', '2', '1'}, 
                                                 {'6', '5', '4'} , 
                                                 {'9', '8', '7'}  });

    BOOST_CHECK(g1 == correct);

}

BOOST_AUTO_TEST_CASE(Grid_connected_component)
{
    ///TODO write IO and change the tests
}

BOOST_AUTO_TEST_CASE(Grid_fill_connected_component)
{
    
}

BOOST_AUTO_TEST_CASE(Grid_fill)
{
    
}

BOOST_AUTO_TEST_SUITE_END()
