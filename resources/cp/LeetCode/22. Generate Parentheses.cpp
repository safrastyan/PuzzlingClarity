class Solution {
public:
    
    bool check(const std::string& s)
    {
        int bal = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++bal;
            }
            if (s[i] == ')') {
                --bal;
            }
            if (bal < 0) {
                return false;
            }
        }
        
        return bal == 0;
    }
    
    vector<string> generateParenthesis(int n) 
    {
        std::vector<std::string> res;
        std::string s;
        for (int i = 0; i < n; ++i) {
            s.push_back('(');
            s.push_back(')');
        }
        std::sort(s.begin(), s.end());
        res.push_back(s);
        while (std::next_permutation(s.begin(), s.end())) {
            if (check(s)) {
                res.push_back(s);
            }
        }
        return res;
    }
};