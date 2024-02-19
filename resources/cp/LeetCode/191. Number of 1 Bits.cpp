class Solution {
public:
std::string to_base(uint32_t n, int b)
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

    int hammingWeight(uint32_t n) {
        auto res = to_base(n, 2);
        return std::count(res.begin(), res.end(), '1'); 
    }
};