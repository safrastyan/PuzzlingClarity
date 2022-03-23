class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        auto f1 = std::find(nums.begin(), nums.end(), target);
        auto f2 = std::find(nums.rbegin(), nums.rend(), target);
        if (f1 == nums.end()) {
            return std::vector<int>{-1, -1};
        }
        return std::vector<int>{static_cast<int>(-std::distance(f1, nums.begin())), static_cast<int>(std::distance(f2, nums.rend() - 1))};
    }
};