class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                ++res;
                ++i;
            }
        }
        return std::vector{res, static_cast<int>(nums.size()) - res * 2};
    }
};