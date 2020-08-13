#pragma once

namespace pc {
namespace algo {

template<int A, int B>
class gcd_tmp
{
public:
    static constexpr int val = gcd_tmp<B, A % B>::val;
};

template<int A>
class gcd_tmp<A, 0>
{
public:
static constexpr int val = A;

};

}
}