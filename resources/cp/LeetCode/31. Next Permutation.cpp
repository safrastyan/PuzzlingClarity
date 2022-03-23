class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        auto result = std::next_permutation(nums.begin(), nums.end());
        if (!result) {
            std::sort(nums.begin(), nums.end());
        }
    }
};