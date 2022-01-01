#define BOOST_TEST_MODULE Stack
#include <boost/test/unit_test.hpp>

#include "ds/Stack.hpp"

#include <stack>

using namespace pc::ds;


template<typename T>
bool same(const Stack<T>& s1, const std::stack<T>& ss1)
{
    auto s = s1;
    auto ss = ss1;
    if (s.size() != ss.size()) {
        return false;
    }
    
    while(!s.empty()) {
        auto t1 = s.top();
        auto t2 = ss.top();
        if (t1 != t2) {
            return false;
        }
        s.pop();
        ss.pop();
    }
    return true;
}


BOOST_AUTO_TEST_SUITE(Stack_tests)

BOOST_AUTO_TEST_CASE(Functional_test)
{
    Stack<int> s;
    std::stack<int> ss;
    for (int i = 0; i < 1000; ++i) {
        s.push(i);
        ss.push(i);
        if (i % 3 == 0) {
            s.pop();
            ss.pop();
        }
    }
    BOOST_CHECK(same(s, ss));
}


BOOST_AUTO_TEST_SUITE_END()
