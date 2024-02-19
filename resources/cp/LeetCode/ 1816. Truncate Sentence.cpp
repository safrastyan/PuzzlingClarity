class Solution {
public:
    string truncateSentence(string s, int k) {
        int x = 0;
        s.push_back(' ');
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                ++x;
            }
            if (x == k) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};