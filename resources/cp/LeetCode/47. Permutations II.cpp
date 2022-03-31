class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        std::sort(nums.begin(), nums.end());
        res.push_back(nums);
        while (std::next_permutation(nums.begin(), nums.end())) {
            res.push_back(nums);
        }
        return res;
    }
};