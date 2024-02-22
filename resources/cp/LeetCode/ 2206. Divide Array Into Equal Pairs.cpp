class Solution {
public:
    bool divideArray(vector<int>& nums) {
        for (auto n: nums) {
            if (std::count(nums.begin(), nums.end(),n) % 2 != 0) {
                return false;
            }
        }
        return true;
    }
};