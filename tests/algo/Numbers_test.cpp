#define BOOST_TEST_MODULE Numbers
#include <boost/test/unit_test.hpp>

#include "algo/Numbers.hpp"
#include "Comparators/Comparators.hpp"

using namespace pc::algo;
using namespace pc::Comparators;

BOOST_AUTO_TEST_SUITE(Numbers_tests)

BOOST_AUTO_TEST_CASE(to_base_test)
{
    BOOST_CHECK_EQUAL(to_base(2, 2), "10");
    BOOST_CHECK_EQUAL(to_base(10, 11), "A");
    BOOST_CHECK_EQUAL(to_base(3, 3), "10");

}

BOOST_AUTO_TEST_CASE(digits_test)
{
    auto d = digits(1230);
    BOOST_CHECK_EQUAL(d.size(), 4);
    BOOST_CHECK_EQUAL(d[0], '0');
    BOOST_CHECK_EQUAL(d[1], '3');
    BOOST_CHECK_EQUAL(d[2], '2');
    BOOST_CHECK_EQUAL(d[3], '1');
    
    d = digits(0);
    BOOST_CHECK_EQUAL(d.size(), 1);
    BOOST_CHECK_EQUAL(d[0], '0');
}

BOOST_AUTO_TEST_CASE(is_prime_test)
{
    BOOST_CHECK(!is_prime(1));
    BOOST_CHECK(!is_prime(4));
    BOOST_CHECK(!is_prime(123));
    BOOST_CHECK(is_prime(2));
    BOOST_CHECK(is_prime(7331));
}

BOOST_AUTO_TEST_CASE(len_test)
{
    BOOST_CHECK_EQUAL(len(10), 2);
    BOOST_CHECK_EQUAL(len(1085), 4);
    BOOST_CHECK_EQUAL(len(1), 1);
}

BOOST_AUTO_TEST_CASE(reverse_test)
{
    
    BOOST_CHECK_EQUAL(reverse(10), 1);
    BOOST_CHECK_EQUAL(reverse(16), 61);
    BOOST_CHECK_EQUAL(reverse(1234), 4321);
    BOOST_CHECK_EQUAL(reverse(667), 766);
}


BOOST_AUTO_TEST_CASE(concat_test)
{
    BOOST_CHECK_EQUAL(concat(100, 3), 1003);
    BOOST_CHECK_EQUAL(concat(103, 33), 10333);
    BOOST_CHECK_EQUAL(concat(999, 12), 99912);
    BOOST_CHECK_EQUAL(concat(65, 55553), 6555553);
}


BOOST_AUTO_TEST_CASE(prime_palindromes_test)
{

}

BOOST_AUTO_TEST_CASE(gcd_test)
{
    BOOST_CHECK_EQUAL(gcd(2, 1), 1);
    BOOST_CHECK_EQUAL(gcd(4, 10), 2);
    BOOST_CHECK_EQUAL(gcd(10, 100), 10);
    BOOST_CHECK_EQUAL(gcd(14, 14), 14);
    BOOST_CHECK_EQUAL(gcd(100, 17), 1);
}

BOOST_AUTO_TEST_CASE(full_binary_test)
{
    BOOST_CHECK_EQUAL(full_binary(1, 3), "100");
    BOOST_CHECK_EQUAL(full_binary(3, 3), "110");
    BOOST_CHECK_EQUAL(full_binary(4, 3), "001");
    
}

BOOST_AUTO_TEST_CASE(to_roman_test)
{
    BOOST_CHECK_EQUAL(to_roman(1), "I");
    BOOST_CHECK_EQUAL(to_roman(4), "IV");
    BOOST_CHECK_EQUAL(to_roman(9), "IX");
}

BOOST_AUTO_TEST_CASE(sieve_prime_numbers_test)
{
    std::vector<int> r1 = {2, 3, 5, 7};
    for (int i = 7; i <= 10; ++i) {
        BOOST_CHECK(is_same(r1, sieve_prime_numbers(i)));
    }
}

BOOST_AUTO_TEST_CASE(gcd_tmp_test)
{
    int x = gcd_tmp<15, 10>::val;
    BOOST_CHECK_EQUAL(gcd(15, 10), x);
}

BOOST_AUTO_TEST_SUITE_END()
