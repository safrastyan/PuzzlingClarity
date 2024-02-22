class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        std::sort(nums.begin(), nums.end());
        int b = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            b = std::max(b, nums[i + 1] - nums[i]);
        }
        return b;
    }
};