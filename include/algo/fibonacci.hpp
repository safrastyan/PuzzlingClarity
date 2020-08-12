#pragma once

/// Thos are fibonacci 
namespace pc {
namespace algo {


/// recursive fibonacci
int fib_rec(int n);


/// dp fibonacci
int fib_dp(int n);

/// template meta programming fibonacci
template<int T>
struct fib_tmp
{
    static constexpr int val = fib_tmp<T - 1>::val + fib_tmp<T - 2>::val;
};

template<>
struct fib_tmp<1>
{
    static constexpr int val = 1;
};


template<>
struct fib_tmp<2>
{
    static constexpr int val = 1;
};

}
}