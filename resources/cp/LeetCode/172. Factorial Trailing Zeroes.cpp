class Solution {
public:
    int trailingZeroes(int n) 
    {
        int five = 5;
        int res = 0;
        while (five <= n) {
            res += n / five;
            five *= 5;
        }
        return res;
    }
};
