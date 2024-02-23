#define BOOST_TEST_MODULE Strings
#include <boost/test/unit_test.hpp>

#include "algo/Strings.hpp"

using namespace pc::algo;

BOOST_AUTO_TEST_SUITE(Strings_tests)

BOOST_AUTO_TEST_CASE(is_palindrome_test)
{
    BOOST_CHECK(!is_palindrome("abc"));
    BOOST_CHECK(is_palindrome("aaa"));
    BOOST_CHECK(is_palindrome("vv"));
}

BOOST_AUTO_TEST_CASE(hamming_distance_test)
{
    BOOST_CHECK_EQUAL(hamming_distance("011", "100"), 3);
    BOOST_CHECK_EQUAL(hamming_distance("1011", "1100"), 3);
    BOOST_CHECK_EQUAL(hamming_distance("000", "000"), 0);
    BOOST_CHECK_EQUAL(hamming_distance("011", "101"), 2);
    
}

BOOST_AUTO_TEST_CASE(is_correct_bracket_expr_test)
{
    std::vector<std::string> correct{"", "(){}[]{}", "(((())))[[{}]]"};
    std::vector<std::string> incorrect{"(", ")", "(()", "{)}"};
    for (auto& s: correct) {
        BOOST_CHECK(is_correct_bracket_expr(s));
    }
    for (auto& s: incorrect) {
        BOOST_CHECK(!is_correct_bracket_expr(s));
    }
}

BOOST_AUTO_TEST_CASE(is_vowel_test)
{
    BOOST_CHECK(is_vowel('a'));
    BOOST_CHECK(is_vowel('e'));
    BOOST_CHECK(!is_vowel('t'));
}

BOOST_AUTO_TEST_CASE(split_test)
{
    BOOST_CHECK_EQUAL(split(" ").size(), 0);
    auto v = split("a b c d");
    BOOST_CHECK_EQUAL(v.size(), 4);
    BOOST_CHECK_EQUAL(v[1], "a");

}
BOOST_AUTO_TEST_SUITE_END()
