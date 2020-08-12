#include "algo/fibonacci.hpp"

#include <vector>

namespace pc {
namespace algo {

int fib_rec(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    return fib_rec(n - 1) + fib_rec(n - 2);
}

int fib_dp(int n)
{
    std::vector<int> res(n + 1, 0);
    res[1] = res[2] = 1;
    for (int i = 3; i <= n; ++i) {
        res[i] = res[i - 1] + res[i - 2];
    }
    return res[n];
}

}

}