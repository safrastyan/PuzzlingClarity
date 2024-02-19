class Solution {
public:

std::string to_base(int n, int b)
{
    std::string res;
    while (n != 0) {
        int r = n % b;
        res.push_back(r < 10 ? static_cast<char>(r + '0') : static_cast<char>(r + 'A' - 10));
        n /= b;
    }
    std::reverse(res.begin(), res.end());
    return res;
}

    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            auto b = to_base(i, 2);
            if (std::count(b.begin(), b.end(), '1') == k) {
                sum += nums[i];
            }
        }
        return sum;

    }
};