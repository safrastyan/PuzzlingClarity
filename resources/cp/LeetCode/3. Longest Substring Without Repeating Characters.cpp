class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        std::set<char> mem;
        int res = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            while (mem.find(s[i]) != mem.end()) {
                mem.erase(s[left]);
                ++left;
            }
            mem.insert(s[i]);
            res = std::max(res, i - left + 1);
        }
        return res;
    }
};