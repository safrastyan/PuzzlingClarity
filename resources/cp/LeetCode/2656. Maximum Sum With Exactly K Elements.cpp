class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int ans = 0;
        --k;
        auto m = *std::max_element(nums.begin(), nums.end());
        return ((m + k) * (m + k + 1)) / 2  - ((m - 1) * m) / 2;
    }
};