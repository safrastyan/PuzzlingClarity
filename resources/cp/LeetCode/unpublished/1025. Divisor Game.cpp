class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> nums(n + 1, false);
        for (int i = 2; i < n + 1; ++i) {
            for (int x = 1; x < i; ++x) {
                if (i % x == 0 && !nums[i - x]) {
                    nums[i] = true;
                    break;
                }
            }
        }   
        return nums[n];
    }
};