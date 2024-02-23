class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res;
        for (auto n: nums1) {
            if (std::find(nums2.begin(), nums2.end(), n) != nums2.end()) {
                res.push_back(n);
            }
        }
        std::sort(res.begin(), res.end());
        auto u = std::unique(res.begin(), res.end());
        res.erase(u, res.end());
        return res;
    }
};