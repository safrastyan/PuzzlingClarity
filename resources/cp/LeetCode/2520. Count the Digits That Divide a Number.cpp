class Solution {
public:
    int countDigits(int num) {
        int res = 0;
        int n = num;
        while (n != 0) {
            if (num % (n % 10) == 0) {
                ++res;
            }
            n /= 10;
        }
        return res;
    }
};