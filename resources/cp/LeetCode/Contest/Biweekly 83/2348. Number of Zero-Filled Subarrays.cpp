class Solution {
public:
    
    long long calc(int x)
    {
        unsigned long long res = x;
        res *= x + 1;
        return res / 2;
        
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        int cur = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++cur;
                continue;
            }
            ans += calc(cur);
            cur = 0;
        }
        if (cur != 0) {
            ans += calc(cur);
        }
        return ans;
    }
};