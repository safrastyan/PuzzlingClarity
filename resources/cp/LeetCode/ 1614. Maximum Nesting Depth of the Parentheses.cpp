class Solution {
public:
    int maxDepth(string s) {
        int bal = 0;
        int best = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++bal;
            }
            if (s[i] == ')') {
                --bal;
            }
            best = std::max(best, bal);
        }
        return best;
    }
};