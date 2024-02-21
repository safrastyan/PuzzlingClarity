class Solution {
public:
    std::vector<int> calc_one(const std::vector<int>& a, const std::vector<int>& b)
    {
        std::vector<int> res;
        for (auto elem: a) {
            if (std::find(b.begin(), b.end(), elem) != b.end()) {
                continue;
            }
            res.push_back(elem);
        }
        return res;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        std::sort(nums1.begin(), nums1.end());
        auto u = std::unique(nums1.begin(), nums1.end());
        nums1.erase(u, nums1.end());

        std::sort(nums2.begin(), nums2.end());
        u = std::unique(nums2.begin(), nums2.end());
        nums2.erase(u, nums2.end());

        return std::vector<std::vector<int>>{calc_one(nums1, nums2), calc_one(nums2, nums1)};    
    }
};