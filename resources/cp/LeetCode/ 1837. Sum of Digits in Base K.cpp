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

    int sumBase(int n, int k) {
        auto s = to_base(n, k);
        int ans = 0;
        for (auto c: s) {
            ans += c - '0';
        }
        return ans;
    }
};