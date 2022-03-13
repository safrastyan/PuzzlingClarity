class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        std::vector<int> a;
        for (auto e: nums1) {
            a.push_back(e);
        }
        for (auto e: nums2) {
            a.push_back(e);
        }
        std::sort(a.begin(), a.end());
        return a.size() % 2 == 1 ? a[a.size() / 2] : (static_cast<double>(a[a.size() / 2 - 1]) + a[a.size() / 2]) / 2;
    }
};