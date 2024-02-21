class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int cur = 0;
        int ans = 0;
        for (auto n: nums) {
            cur += n;
            if (cur == 0) {
                ++ans;
            }
        }
        return ans;
    }
};