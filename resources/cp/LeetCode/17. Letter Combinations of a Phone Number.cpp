class Solution {
public:
    
    void rec(const std::string& digits, std::string& cur, int index, const std::vector<std::string>& all, std::vector<std::string>& ans)
    {
        if (index == digits.size()) {
            ans.push_back(cur);
            return;
        }
        std::string s = all[digits[index] - '0' - 2];
        for (int i = 0; i < s.size(); ++i) {
            cur.push_back(s[i]);
            rec(digits, cur, index + 1, all, ans);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) {
            return std::vector<std::string>();
        }
        std::string cur;
        std::vector<std::string> all{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::vector<std::string> ans;
        rec(digits, cur, 0, all, ans);    
        return ans;
    }
};