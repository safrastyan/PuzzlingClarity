class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        std::vector<int> res;
        for (int i = 0; i < m; ++i) {
            res.push_back(nums1[i]);
        }
        for (int i = 0; i < n; ++i) {
            res.push_back(nums2[i]);
        }
        std::sort(res.begin(), res.end());
        nums1 = res;
    }
};