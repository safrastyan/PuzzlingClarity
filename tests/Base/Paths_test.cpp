#define BOOST_TEST_MODULE Paths
#include <boost/test/unit_test.hpp>

#include "Base/Paths.hpp"

#include <algorithm>
#include <iostream>

using namespace pc::base::paths;

BOOST_AUTO_TEST_SUITE(Paths_tests)

BOOST_AUTO_TEST_CASE(basic_test)
{
    BOOST_CHECK(pc_path().size() != 0);
    BOOST_CHECK(resources_path().size() != 0);
    std::cout << pc_path() << std::endl << resources_path() << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
