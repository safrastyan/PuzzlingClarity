class Solution {
public:
    int numberOfMatches(int n) {
        int res = 0;
        while (n != 1) {
            int extra = n % 2 == 0 ? 0 : 1;
            res += n / 2;
            n /= 2;
            n += extra;
        }
        return res;
    }
};