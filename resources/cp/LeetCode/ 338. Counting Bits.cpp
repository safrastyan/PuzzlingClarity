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

    vector<int> countBits(int n) {
        std::vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            auto b = to_base(i, 2);
            ans.push_back(std::count(b.begin(), b.end(), '1'));
        }
        return ans;
    }
};