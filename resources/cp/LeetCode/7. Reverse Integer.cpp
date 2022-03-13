class Solution {
public:
    int reverse(int x) 
    {
        auto low = static_cast<long long>(std::numeric_limits<int>::min());
        auto high = static_cast<long long>(std::numeric_limits<int>::max());
        
        std::string s = std::to_string(x);
        int sign = 1;
        if (s[0] == '-') {
            s.erase(0, 1);
            sign = -1;
        }
        std::reverse(s.begin(), s.end());
        long long res = std::stoll(s.c_str()) * sign;
        if (res > high || res < low) {
            res = 0;
        }
        return static_cast<int>(res);
    }
};