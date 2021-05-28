#define BOOST_TEST_MODULE DP
#include <boost/test/unit_test.hpp>

#include "algo/BigInt.hpp"
#include "Base/Paths.hpp"
#include "io/io.hpp"

using namespace pc::algo;
using namespace pc::base::paths;
using namespace pc::io;

BOOST_AUTO_TEST_SUITE(BigInt_tests)

BOOST_AUTO_TEST_CASE(bigint_arithhm_test)
{
    std::string path = algo_tests_path() + "/bigint/bigint_arithm";
    for (int t = 1; t <= 2; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        
    }
}

BOOST_AUTO_TEST_CASE(bigint_logic_test)
{
    std::string path = algo_tests_path() + "/bigint/bigint_logic";
    for (int t = 1; t <= 1; ++t) {
        std::fstream input(path + std::to_string(t) + ".in");        
        std::fstream output(path + std::to_string(t) + ".out");
        
    }
}

BOOST_AUTO_TEST_SUITE_END()
