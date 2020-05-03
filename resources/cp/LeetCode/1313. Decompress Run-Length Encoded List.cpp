class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size() / 2; ++i) {
            vector<int> cur(nums[2 * i], nums[2 * i + 1]);
            res.insert(res.end(), cur.begin(), cur.end());
        }
        return res;
    }
};