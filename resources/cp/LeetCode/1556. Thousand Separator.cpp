class Solution {
public:
    string thousandSeparator(int n) 
    {
        auto s = std::to_string(n);
        string res;
        int j = 0;
        for (int i = s.size() - 1; i >= 0; --i) {
            ++j;
            res.push_back(s[i]);
            if (j == 3) {
                j = 0;
                res.push_back('.');
            }
        }
        std::reverse(res.begin(), res.end());
        if (res[0] == '.') {
            res.erase(0, 1);
        }
        return res;
        
    }
};