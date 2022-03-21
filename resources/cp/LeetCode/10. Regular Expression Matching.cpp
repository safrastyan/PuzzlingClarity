class Solution {
public:
    
    bool is_pattern_empty(const std::string& p)
    {
        int c = std::count(p.begin(), p.end(), '*');
        return c == p.size() / 2 && p.size() % 2 == 0;
    }
    
    std::string cut_prefix(const std::string& s, int pref)
    {
        return s.substr(pref, s.size() - pref);
    }
    
    void rec(std::string s, std::string p, bool& ans)
    {
        if (p.empty()) {
            if (s.empty()) {
                ans = true;
            }
            return;
        }
        
        if (s.empty()) {
            if (is_pattern_empty(p)) {
                ans = true;
            }
            return;
        }
     
        if (p.size() == 1) {
            if (s[0] == p[0] || p[0] == '.') {
                rec(cut_prefix(s, 1), cut_prefix(p, 1), ans);
            }
            return;
        }
        
        if (p[1] == '*') {
            rec(s, cut_prefix(p, 2), ans);
            if (p[0] == '.' || p[0] == s[0]) {
                rec(cut_prefix(s, 1), p, ans);
            }
            return;
        }
        
        if (p[0] == s[0] || p[0] == '.') {
            rec(cut_prefix(s, 1),  cut_prefix(p, 1), ans);
        }
        
    }
    
    bool isMatch(string s, string p) {
        bool ans = false;
        rec(s, p, ans);
        return ans;
    }
};