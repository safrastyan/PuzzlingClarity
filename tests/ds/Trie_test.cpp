#define BOOST_TEST_MODULE Trie
#include <boost/test/unit_test.hpp>

#include "ds/Trie.hpp"

using namespace pc::ds;

BOOST_AUTO_TEST_SUITE(Trie_tests)

BOOST_AUTO_TEST_CASE(Basic_test)
{

    Trie t;
    t.add_word("abc");
    BOOST_CHECK(t.exists("abc"));
}

BOOST_AUTO_TEST_SUITE_END()
