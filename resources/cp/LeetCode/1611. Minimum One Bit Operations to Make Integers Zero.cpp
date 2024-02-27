class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            if ((n & (1 << i)) == 0) {
                continue;
            }
            ans = ((1 << (i + 1)) - 1) - ans;
        }
        return ans;
    }
};