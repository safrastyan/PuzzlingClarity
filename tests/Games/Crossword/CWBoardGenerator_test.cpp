#define BOOST_TEST_MODULE CWBoardGenerator
#include <boost/test/unit_test.hpp>

#define private public

#include "Games/Crossword/CWBoardGenerator.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"

#include <algorithm>
#include <iostream>

using namespace pc::games::crossword;
using namespace pc::base::paths;

CWBoardGenerator* g;

BOOST_AUTO_TEST_SUITE(CWBoardGenerator_tests)

BOOST_AUTO_TEST_CASE(node_all_cords_test)
{
    
    Node n;
    n.row = 1;
    n.col = 0;
    n.len = 5;
    n.across = false;
    auto res = n.all_coords();
    BOOST_CHECK_EQUAL(res.size(), 5);
}

BOOST_AUTO_TEST_CASE(blueprint_test)
{
    g = new CWBoardGenerator(13, 13, linx_standard_dictionary_path());
    CWBoardGeneratorConfig c;
    c.template_id = 1;
    g->config(c);
    std::cout << "Board is " << std::endl;    
}

BOOST_AUTO_TEST_CASE(do_intersect_node_test)
{
    std::cout << "Node intersection " << std::endl;
    Node n1, n2;
    n1.row = 2;
    n1.col = 2;
    n1.len = 5;
    n1.across = true;
    n2.row = 0;
    n2.col = 3;
    n2.len = 5;
    n2.across = false;
    auto res = g->do_intersect(n1, n2);
    BOOST_CHECK_EQUAL(res.pos1, 1);
    BOOST_CHECK_EQUAL(res.pos2, 2);
}

BOOST_AUTO_TEST_CASE(node_intersections_test)
{
    std::cout << "Testing intersections" << std::endl;
    int x = 0;
    for (auto& inters: g->m_node_intersections) {
        std::cout << "For " << x << " node " << std::endl;
        ++x;
        for (auto& inter: inters) {
            std::cout << inter.node1_id << " " << inter.node2_id << " " << inter.pos1 << " " << inter.pos2 << std::endl;
        }
    }
}

BOOST_AUTO_TEST_SUITE_END()


