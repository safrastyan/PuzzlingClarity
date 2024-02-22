class Solution {
public:
    int totalMoney(int n) {
        int mond = 0;
        int ans = 0;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 7 == 0) {
                ++mond;
                ans += mond;
                prev = mond;
                continue;
            }
            ++prev;
            ans += prev;
        }
        return ans;
    }
};