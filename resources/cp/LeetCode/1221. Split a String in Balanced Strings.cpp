class Solution {
public:
    int balancedStringSplit(string s) {
        int bal = 0;
        int res = 0;
        
        for (auto c: s) {
            bal += c == 'L' ? 1 : -1;
            if (bal == 0) {
                ++res;
            }
        }
        
        return res;
    }
};

