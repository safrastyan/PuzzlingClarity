class Solution {
public:
    std::vector<int> next(const std::vector<int>& a)
    {
        std::vector<int> res;
        for (int i = 0; i < a.size() - 1; ++i) {
            res.push_back((a[i] + a[i + 1]) % 10);
        }
        return res;
    }

    int triangularSum(vector<int>& nums) {
        while (nums.size() > 1) {
            nums = next(nums);
        }
        return nums.front();
    }
};