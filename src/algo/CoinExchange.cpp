#include "algo/CoinExchange.hpp"

namespace pc {
namespace algo {

int coin_exchange(const std::vector<int>& coins, int n) 
{
    if (n < 0) {
        return 0;
    }
    if (coins.empty()) {
        return 0;
    }
    std::vector<int> temp(n + 1, 0);
    temp[0] = 1;
    for (int coin: coins) {
        for (int i = coin; i <= n; ++i) {
            temp[i] += temp[i - coin];
        }
    }
    return temp[n];
}

}
}
