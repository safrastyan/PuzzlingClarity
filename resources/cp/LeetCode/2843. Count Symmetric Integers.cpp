class Solution {
public:
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

    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; ++i) {
            auto dig = digits(i);
            if (dig.size() % 2 == 1) {
                continue;
            }
            ans += std::accumulate(dig.begin(), dig.begin() + dig.size() / 2, 0) == std::accumulate(dig.begin() + dig.size() / 2, dig.end(), 0) ? 1 : 0;
        }
        return ans;
    }
};