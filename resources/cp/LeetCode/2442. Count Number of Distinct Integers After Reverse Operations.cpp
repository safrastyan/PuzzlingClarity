class Solution {
public:
    int reverse(int n)
    {
        auto d = digits(n);
        int res = 0;
        int ten = 1;
        for (int i = d.size() - 1; i >= 0; --i) {
            res += ten * static_cast<int>(d[i] - '0');
            ten *= 10;
        }
        return res;
    }

    std::vector<char> digits(int n)
    {
        std::vector<char> res;
        if (n == 0) {
            res.push_back('0');
            return res;
        }
        while (n != 0) {
            res.push_back('0' + n % 10);
            n /= 10;
        }
        return res;
    }

    int countDistinctIntegers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            nums.push_back(reverse(nums[i]));
        }
        std::sort(nums.begin(), nums.end());
        return std::unique(nums.begin(), nums.end()) - nums.begin();
    }
};