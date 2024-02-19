class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        std::vector<int> res{nums.front()};
        for (int i = 1; i < nums.size(); ++i) {
            res.push_back(res.back() + nums[i]);
        }
        return res;
    }
};