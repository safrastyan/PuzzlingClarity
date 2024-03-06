class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        std::sort(tokens.begin(), tokens.end());
        int left = 0;
        int right = tokens.size() - 1;
        int best = 0;
        int cur = 0;
        while (left <= right) {
            if (power >= tokens[left]) {
                ++cur;
                power -= tokens[left];
                ++left;
            } else { 
                --cur;
                power += tokens[right];
                --right;
            }
            if (cur < 0) {
                break;
            }
            best = std::max(best, cur);
        }
        return best;
    }
};