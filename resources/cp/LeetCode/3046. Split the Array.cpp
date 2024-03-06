class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        for (auto n: nums) {
            if (std::count(nums.begin(), nums.end(), n) > 2) {
                return false;
            }
        }        
        return true;
    }
};