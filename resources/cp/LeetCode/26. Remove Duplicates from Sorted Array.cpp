class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        auto f = std::unique(nums.begin(), nums.end());
        return f - nums.begin();
    }
};