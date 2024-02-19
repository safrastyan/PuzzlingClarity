class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int res = 0;
        std::sort(piles.begin(), piles.end());
        for (int i = piles.size() - 2, j = 0; j < piles.size() / 3; i -= 2, ++j) {
            res += piles[i];
        }
        return res;
    }
};