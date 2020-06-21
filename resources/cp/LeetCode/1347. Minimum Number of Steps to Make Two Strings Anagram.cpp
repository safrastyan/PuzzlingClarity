class Solution {
public:
    int minSteps(string s, string t) 
    {
        int res = 0;
        for (int i = 0; i < 26; ++i) {
            int a = std::count(s.begin(), s.end(), 'a' + i);
            int b = std::count(t.begin(), t.end(), 'a' + i);
            if (a > b) {
                res += a - b;
            }
        }
        return res;
    }
};