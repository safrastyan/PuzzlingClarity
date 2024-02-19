class Solution {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        std::vector<int> p{2, 3, 5};
        for (auto pp: p) {
            while (n % pp == 0) {
                n /= pp;
            }
        }
        return n == 1;
    }
};