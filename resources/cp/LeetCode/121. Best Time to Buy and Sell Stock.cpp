class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int min_price = prices[0];
        int prof = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min_price = std::min(min_price, prices[i]);
            prof = std::max(prof, prices[i] - min_price);
        }
        return prof;
    }
};