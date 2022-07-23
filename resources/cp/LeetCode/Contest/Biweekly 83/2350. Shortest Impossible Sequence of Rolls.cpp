class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) 
    {
        std::vector<int> mark(k + 1, 0);
        int rem = k;
        int res = 0;
        for (int i = 0; i < rolls.size(); ++i) {
            int x = rolls[i];
            if (mark[x] == 0) {
                mark[x] = 1;
                --rem;
            }
            if (rem == 0) {
                ++res;
                mark = std::vector<int>(k + 1, 0);
                rem = k;
            }
        }
        return res + 1;
    }
};