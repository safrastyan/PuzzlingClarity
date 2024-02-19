class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        std::vector<int> nums;
        for (const auto& b: bank) {
            int x = std::count(b.begin(), b.end(), '1');
            if (x == 0) {
                continue;
            }
            nums.push_back(x);
        }
        int ans = 0;
        for (int i = 0; i < int(nums.size()) - 1; ++i) {
            ans += nums[i] * nums[i + 1];
        }
        return ans;
    }
};