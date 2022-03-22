class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        std::sort(nums.begin(), nums.end());
        long long ans = std::numeric_limits<long long>::max() - std::numeric_limits<int>::max();
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                if (std::abs(target - current_sum) < std::abs(ans - target)) {
                    ans = current_sum;
                }
                if (current_sum < target) {
                    ++left;
                    continue;
                }
                --right;
            }
        }
        return static_cast<int>(ans);
    }
};