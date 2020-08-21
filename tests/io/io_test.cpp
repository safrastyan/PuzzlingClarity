#define BOOST_TEST_MODULE io
#include <boost/test/unit_test.hpp>

#include "io/io.hpp"
#include "Comparators/Comparators.hpp"
#include "Base/Paths.hpp"

#include <fstream>

using namespace pc::io;
using namespace pc::Comparators;
using namespace pc::base::paths;

BOOST_AUTO_TEST_SUITE(io_tests)

BOOST_AUTO_TEST_CASE(read_one_test)
{
    std::ifstream fin(io_tests_path() + "/one_number.in");
    auto x = read_one<int>(fin);
    fin = std::ifstream(io_tests_path() + "/one_string.in");
    auto s = read_one<std::string>(fin);

    BOOST_CHECK_EQUAL(x, 12);
    BOOST_CHECK_EQUAL(s, std::string("ABCd"));
}
BOOST_AUTO_TEST_CASE(read_array_test)
{
    std::ifstream fin(io_tests_path() + "/array_int.in");
    auto a_int = read_array<int>(fin);
    fin = std::ifstream(io_tests_path() + "/array_int_u.in");
    auto a_int_u = read_array_u<int>(fin);
    BOOST_CHECK(is_same(a_int, a_int_u));
}

BOOST_AUTO_TEST_SUITE_END()
