class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[0] && nums[i] != nums.back()) {
                return nums[i];
            }
        }
        return -1;
    }
};