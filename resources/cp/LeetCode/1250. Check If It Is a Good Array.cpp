class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        auto g = 0;
        for (auto elem:nums) {
            g = gcd(g, elem);
        }
        return g == 1;
    }
};