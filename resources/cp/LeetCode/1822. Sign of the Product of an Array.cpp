class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        int sign = 1;
        for (auto n: nums) {
            if (n == 0) {
                return 0;
            }
            if (n < 0) {
                sign *= -1;
                continue;
            }
        }
        return sign;
    }
};