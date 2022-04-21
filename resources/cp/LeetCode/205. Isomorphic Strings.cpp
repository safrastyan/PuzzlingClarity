class Solution {
public:
    
    bool check(const std::string& s, const std::string& t)
    {
        std::map<char, char> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[i];
                continue;
            }
            if (m[s[i]] != t[i]) {
                return false;
            } 
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) 
    {
        return check(s, t) && check(t, s);    
    }
};