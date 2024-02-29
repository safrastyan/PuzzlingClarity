class Solution {
public:
    int bitwiseComplement(int n) {
        int a = 1;
        while (a < n) {
            a <<= 1;
            ++a;
        }
        return a ^ n;
    }
};