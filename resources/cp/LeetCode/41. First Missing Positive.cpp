class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i >= 0; ++i) {
            if (!std::binary_search(nums.begin(), nums.end(), i)) {
                return i;
            }
        }
        return -1;
    }
};