class Solution {
public:
    int calc_one(const std::vector<int>& a, int i, int j)
    {
        std::vector<int> temp;
        temp.insert(temp.end(), a.begin() + i, a.begin() + j + 1);
        std::sort(temp.begin(), temp.end());
        auto u = std::unique(temp.begin(), temp.end());
        int d = u - temp.begin();
        return d * d;
    }
    
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                ans += calc_one(nums, i, j);
            }
        }
        return ans;
    }
};