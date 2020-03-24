class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for (auto n: nums) {
            int c = 0 ;
            for (auto nn: nums) {
                if (nn < n) {
                    ++c;
                }
            }
            res.push_back(c);
        }
        return res;
    }
};