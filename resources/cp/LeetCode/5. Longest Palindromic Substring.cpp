class Solution {
public:
    
    void rec(const std::string& s, int left, int right, std::string& ans)
    {
        if (left < 0 || right >= s.size()) {
            return;
        }
        if (s[left] != s[right]) {
            return;
        }
        if (right - left + 1 > ans.size()) {
            ans = s.substr(left, right - left + 1);
        }
        
        rec(s, left - 1, right + 1, ans);
    }
    
    string longestPalindrome(string s) 
    {
        std::string ans;
        ans.push_back(s[0]);
        for(int i = 0; i < s.size() - 1; ++i) {
            rec(s, i, i, ans);
            rec(s, i, i + 1, ans);
        }
        return ans;
    }
};