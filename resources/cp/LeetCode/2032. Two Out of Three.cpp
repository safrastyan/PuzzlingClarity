class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        std::vector<int> res;
        for (int i = 1; i <= 100; ++i) {
            int c = 0;
            c += std::find(nums1.begin(), nums1.end(), i) == nums1.end() ? 0 : 1;
            c += std::find(nums2.begin(), nums2.end(), i) == nums2.end() ? 0 : 1;
            c += std::find(nums3.begin(), nums3.end(), i) == nums3.end() ? 0 : 1;
            if (c < 2) {
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};