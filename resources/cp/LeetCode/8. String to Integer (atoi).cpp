class Solution {
public:
    
    void clear_head(std::string& s)
    {
        int i = 0;
        while (s[i] == ' ') {
            ++i;
        }
        s.erase(0, i);
    }
    
    void clear_zeroes(std::string& s)
    {
        int i = 0;
        while (s[i] == '0') {
            ++i;
        }
        s.erase(0, i);
    }
    
    int clamp_sign(std::string& s)
    {
        int sign = 1;
        if (s[0] == '-') {
            sign = -1;
            s.erase(0, 1);
            return sign;
        }
        if (s[0] == '+') {
            s.erase(0, 1);
        }
        return sign;
    }
    
    void clear_tail(std::string& s)
    {
        if (!std::isdigit(s[0])) {
            s = "0";
            return;
        }
        int i = 0;
        while (i < s.size() && std::isdigit(s[i])) {
            ++i;
        }
        s = s.substr(0, i);
    }
    
    int final_convert(std::string& s, int sign)
    {
        auto low = static_cast<long long>(std::numeric_limits<int>::min());
        auto high = static_cast<long long>(std::numeric_limits<int>::max());
        long long ans = 0;
        long long ten = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            ans += ten * (s[i] - '0');
            
            if (sign == -1) {
                if (-ans <= low || -ten <= low) {
                    return low;
                }
            } else {
                if (ans >= high || ten >= high) {
                    return high;
                }
            }
            ten *= 10;
        }
        return ans * sign;
    }
    
    int myAtoi(string s) 
    {
        clear_head(s);
        int sign = clamp_sign(s);
        clear_zeroes(s);
        clear_tail(s);
        return final_convert(s, sign);
    }
};