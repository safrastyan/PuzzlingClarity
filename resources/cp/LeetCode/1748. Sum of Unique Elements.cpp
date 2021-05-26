class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (std::count(nums.begin(), nums.end(), nums[i]) == 1) {
                sum += nums[i];
            }
        }
        return sum;
    }
};