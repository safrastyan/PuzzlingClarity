#define BOOST_TEST_MODULE Vector
#include <boost/test/unit_test.hpp>

#include "ds/Vector.hpp"

using namespace pc::ds;


template<typename T>
bool same(const Vector<T> v, const std::vector<T> sv)
{
    if (v.size() != sv.size()) {
        return false;
    }
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] != sv[i]) {
            return false;
        }
    }
    return true;
}


BOOST_AUTO_TEST_SUITE(Vector_tests)

BOOST_AUTO_TEST_CASE(Construction_test)
{

    Vector<int> v(10, 10);
    std::vector<int> sv(10, 10);
    BOOST_CHECK(same(v, sv));

}

BOOST_AUTO_TEST_CASE(Functional_test)
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::vector<int> sv{1, 2, 3};
    
    for (int i = 0; i < 10000; ++i) {
        v.push_back(i);
        sv.push_back(i);
        BOOST_CHECK(same(v, sv));
    }

    for (int i = 0; i < 10000; ++i) {
        v.pop_back();
        sv.pop_back();
        BOOST_CHECK(same(v, sv));
    }
}

BOOST_AUTO_TEST_SUITE_END()
