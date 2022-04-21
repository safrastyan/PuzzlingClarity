class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
        
        std::unordered_set<int> s;
        for (int i = 0; i <= k; ++i) {
            if (i == nums.size()) {
                return false;
            }
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        for (int i = k + 1; i < nums.size(); ++i) {
            s.erase(nums[i - k - 1]);
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};