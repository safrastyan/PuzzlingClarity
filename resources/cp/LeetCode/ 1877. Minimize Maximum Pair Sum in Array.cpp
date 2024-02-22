class Solution {
public:
    int minPairSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int b = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            b = std::max(b, nums[i] + nums[nums.size() - i - 1]);
        }
        return b;
    }
};