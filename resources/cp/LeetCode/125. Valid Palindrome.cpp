class Solution {
public:
    
    std::string fix(const std::string& s)
    {
        std::string res;
        for(auto c: s) {
            if (!std::isalnum(c)) {
                continue;
            }
            res.push_back(std::tolower(c));
        }
        return res;
    }
    
    bool check(const std::string& s)
    {
        for (int i = 0; i < s.size() / 2; ++i) {
            if (s[i] != s[s.size() - i -1]) {
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(string s) 
    {
        return check(fix(s));
    }
};