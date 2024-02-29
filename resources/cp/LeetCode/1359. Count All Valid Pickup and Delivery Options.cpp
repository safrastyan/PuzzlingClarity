class Solution {
public:
    int countOrders(int n) {
        long long mod = 1000000007;
        long long ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans *= i * (i * 2 - 1);
            ans %=  mod;
        }
        return ans;
    }
};