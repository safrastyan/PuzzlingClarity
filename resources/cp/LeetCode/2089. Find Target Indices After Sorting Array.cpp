class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        std::vector<int> res;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target) {
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};