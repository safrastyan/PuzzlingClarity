#define BOOST_TEST_MODULE DP
#include <boost/test/unit_test.hpp>

#include "algo/BigInt.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(BigInt_tests)

BOOST_AUTO_TEST_CASE(bigint_constructor_test)
{
    BOOST_CHECK_EQUAL(BigInt("-123"), BigInt(-123));
    BOOST_CHECK_NE(BigInt("-1233"), BigInt(-123));
    BOOST_CHECK_LT(BigInt("123"), BigInt("234"));
    BOOST_CHECK_LT(BigInt("123"), BigInt("1344"));
    BOOST_CHECK_LT(BigInt("-123"), BigInt("1344"));
    BOOST_CHECK_LT(BigInt("-12"), BigInt("-11"));
    BOOST_CHECK_LE(BigInt("-12"), BigInt("-11"));
    // BOOST_CHECK_EQUAL(BigInt("-1"), BigInt("-11"));
    BOOST_CHECK_LT(BigInt("-1"), BigInt("-11"));
    BOOST_CHECK_LE(BigInt("-1"), BigInt("-11"));
}


// BOOST_AUTO_TEST_CASE(bigint_arithm_test)
// {
//     std::string path = algo_tests_path() + "/bigint/bigint_arithm";
//     for (int t = 1; t <= 2; ++t) {
//         std::fstream input(path + std::to_string(t) + ".in");
//         std::fstream output(path + std::to_string(t) + ".out");
        
//     }
// }

// BOOST_AUTO_TEST_CASE(bigint_logic_test)
// {
//     std::string path = algo_tests_path() + "/bigint/bigint_logic";
//     for (int t = 1; t <= 1; ++t) {
//         std::fstream input(path + std::to_string(t) + ".in");        
//         std::fstream output(path + std::to_string(t) + ".out");
        
//     }
// }

BOOST_AUTO_TEST_SUITE_END()
