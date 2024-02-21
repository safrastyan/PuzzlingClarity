class Solution {
public:
    bool check(const std::string& s, int rr)
    {
        bool r, g, b;
        r = g = b = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0' + rr) {
                switch(s[i - 1]) {
                case 'R':
                    r = true;
                    break;
                case 'G':
                    g = true;
                    break;
                case 'B':
                    b = true;
                    break;
                }
            }
        }
        return r && g && b;
    }
    int countPoints(string rings) {
        int ans = 0;
        for (int i = 0; i <= 9; ++i) {
            if (check(rings, i)) {
                ++ans;
            }
        }   
        return ans;
    }
};