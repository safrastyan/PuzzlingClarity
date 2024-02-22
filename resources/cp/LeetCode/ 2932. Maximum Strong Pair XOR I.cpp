class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        for (int i = 0 ; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (std::abs(nums[i] - nums[j]) <= std::min(nums[i], nums[j])) {
                    res = std::max(res, nums[i] ^ nums[j]);
                }
            }
        }
        return res;
    }
};