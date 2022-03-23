class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        auto f = std::find(nums.begin(), nums.end(), target);
        return f == nums.end() ? -1 : f - nums.begin();
    }
};