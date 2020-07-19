#define BOOST_TEST_MODULE Sets
#include <boost/test/unit_test.hpp>

#include "algo/Sets.hpp"
#include "io/io.hpp"

using namespace pc::algo;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(Sets_tests)

BOOST_AUTO_TEST_CASE(generate_all_subsets_test)
{
    std::vector<char> a{'a', 'b', 'c'};
    auto res = generate_all_subsets(a);
    BOOST_CHECK_EQUAL(res.size(), 8);
    
}

BOOST_AUTO_TEST_CASE(KalmostSqualSubsets_test)
{
    std::vector<int> a = {1, 4, 5, 5, 10, 6, 7, 7};
    auto res = k_almost_equal_subsets(a, 3);
    write(a, "For k=3 and array ");
    write(res, "Bucket");

    res = k_almost_equal_subsets(a, 4);
    write(a, "For k=4 and array ");
    write(res, "Bucket");
    

}

BOOST_AUTO_TEST_SUITE_END()
