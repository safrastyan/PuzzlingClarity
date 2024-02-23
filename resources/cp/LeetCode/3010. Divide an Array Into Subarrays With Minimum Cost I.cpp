class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int ans = nums[0];
        auto m = std::min_element(nums.begin() + 1, nums.end());
        ans += *m;
        nums.erase(m);
        return ans + *std::min_element(nums.begin() + 1, nums.end());
    }
};