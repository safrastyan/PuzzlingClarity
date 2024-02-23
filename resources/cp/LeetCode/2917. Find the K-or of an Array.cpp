class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int ans = 0;
        
        for (int i = 0; i < 32; ++i) {
            int ch = 0;
            for (auto n: nums) {
                if ( (n >> 32 - i - 1) & 1) {
                    ++ch;
                }
            }
            if (ch >= k) {
                ans |= (1 << 32 - i - 1);
            }
        }
        return ans;
    }
};