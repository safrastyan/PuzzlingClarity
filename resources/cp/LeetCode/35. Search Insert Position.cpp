class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        auto f = std::lower_bound(nums.begin(), nums.end(), target);
        return f - nums.begin();
    }
};