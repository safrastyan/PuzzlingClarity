class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        long long sum, ans;
        sum = ans = std::numeric_limits<int>::min();
        
        for (int i = 0; i < nums.size(); ++i) {
            sum = std::max(static_cast<long long>(nums[i]), sum + nums[i]);
            ans = std::max(sum, ans);
        }
        return static_cast<int>(ans);
    }
};