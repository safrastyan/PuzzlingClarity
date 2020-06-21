class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) 
    {
        std::vector<int> res = prices;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    res[i] -= prices[j];
                    break;
                }
            }
        }
        return res;
    }
};