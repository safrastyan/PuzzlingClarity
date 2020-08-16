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

BOOST_AUTO_TEST_CASE(read_array_tests)
{
    std::ifstream fin(io_tests_path() + "/array_int.in");
    auto a_int = read_array<int>(fin);
    fin = std::ifstream(io_tests_path() + "/array_int_u.in");
    auto a_int_u = read_array_u<int>(fin);
    BOOST_CHECK(is_same(a_int, a_int_u));
}

BOOST_AUTO_TEST_SUITE_END()
