class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans = 0;
        for (auto n: nums) {
            ans |= n;
        }
        return ans;
    }
};