class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < nums.size() / 2; ++i) {
            res += nums[i * 2];
        }
        return res;
    }
};