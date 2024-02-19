class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int best = 1;
        int best_elem = nums[0];
        int cur = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                ++cur;
                if (cur > best) {
                    best = cur;
                    best_elem = nums[i];
                }
                continue;
            }
            cur = 1;
        }
        return best_elem;
    }
};