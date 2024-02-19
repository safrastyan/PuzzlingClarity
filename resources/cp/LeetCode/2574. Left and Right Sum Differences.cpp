class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int l = std::accumulate(nums.begin(), nums.begin() + i, 0);
            int r = std::accumulate(nums.begin() + i + 1, nums.end(), 0);
            res.push_back(std::abs(l - r));
        }
        return res;
    }
};