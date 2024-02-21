class Solution {
public:
    int calc_one(const std::vector<int>& a, const std::vector<int>& b)
    {
        int ans = 0;
        for (auto elem: a) {
            if (std::find(b.begin(), b.end(), elem) == b.end()) {
                continue;
            }
            ++ans;
        }
        return ans;
    }
    
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        return std::vector<int>{calc_one(nums1, nums2), calc_one(nums2, nums1)};    
    }
};