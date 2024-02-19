class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s = std::accumulate(nums.begin(), nums.end(), 0);
        int d = 0;
        for (auto n: nums) {
            while (n != 0) {
                d += n % 10;
                n /= 10;
            }
        }
        return std::abs(s - d);
    }
};