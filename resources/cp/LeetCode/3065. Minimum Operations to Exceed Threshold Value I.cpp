class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = 0;
        for (auto e: nums) {
            if (e < k) {
                ++a;
            }
        }
        return a;
    }
};