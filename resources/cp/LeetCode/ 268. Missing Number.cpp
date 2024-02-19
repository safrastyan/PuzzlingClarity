class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int all = ((nums.size() * (nums.size() + 1))) / 2;
        return all - std::accumulate(nums.begin(), nums.end(), 0);
    }
};