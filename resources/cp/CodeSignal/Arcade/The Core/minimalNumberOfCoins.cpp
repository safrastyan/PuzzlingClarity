int minimalNumberOfCoins(std::vector<int> coins, int price) 
{
    int res = 0;
    int i = coins.size() - 1;
    while (price != 0) {
        int num = price / coins[i];
        res += num;
        price -= num * coins[i];
        --i;
    }
    return res;
}
