class Solution {
public:
    
    bool check(const std::vector<std::string>& strs, const std::string& s)
    {
        for (auto& ss: strs) {
            if (ss.find(s) != 0) {
                return false;
            }
        }
        return true;
        
    }
    
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 1) {
            return strs[0];
        }
        std::string res;
        std::string s = strs[0];
        for (int i = s.size(); i >= 0; --i) {
            std::string sub = s.substr(0, i);
            if (check(strs, sub)) {
                return sub;
            }
        }
        return res;
    }
};