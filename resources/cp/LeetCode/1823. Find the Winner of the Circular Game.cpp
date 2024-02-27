class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 1; i <= n; ans += k, ans %= i, ++i);
        return ans + 1;
    }
};