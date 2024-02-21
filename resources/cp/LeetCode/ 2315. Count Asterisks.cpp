class Solution {
public:
    int countAsterisks(string s) {
        int ans = 0;
        bool inside = false;
        for (auto c: s) {
            if(c == '|') {
                inside = !inside;
            }
            if (c == '*' && !inside) {
                ++ans;
            }
        }
        return ans;
    }
};