class Solution {
public:
    bool isSameAfterReversals(int num) {
        if (num == 0) {
            return true;
        }
        return num % 10 != 0;
    }
};