#define BOOST_TEST_MODULE ArrayGenerators
#include <boost/test/unit_test.hpp>

#include "Comparators/Comparators.hpp"

#include <vector>

BOOST_AUTO_TEST_SUITE(Comparators_tests)

BOOST_AUTO_TEST_CASE(is_same_tmp_vectors_test)
{
    std::vector<int> a{1, 2, 3};
    auto b = a;
    BOOST_CHECK(pc::Comparators::is_same(a, b));

    b[2] = 10;
    BOOST_CHECK(!pc::Comparators::is_same(a, b));
}

BOOST_AUTO_TEST_CASE(same_double_test)
{
    pc::Comparators::same_double(1, 1.00000001);
}


BOOST_AUTO_TEST_SUITE_END()
