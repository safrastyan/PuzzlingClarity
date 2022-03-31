class Solution {
public:
    
    int next(const std::string& s, int i)
    {
        char c = s[i];
        while (i < s.size() && c == s[i]) {
            ++i;
        }
        return i;
    }
    
    std::string cs(const std::string& s)
    {
        std::string res;
        int i = 0;
        while (i < s.size()) {
            auto p = next(s, i);
            res += std::to_string(p - i);
            res.push_back(s[i]);
            i = p;
        }
        return res;
    }
    
    string countAndSay(int n) 
    {
        std::string res = "1";
        for (int i = 0; i < n - 1; ++i) {
            res = cs(res);
        }
        return res;
    }
};