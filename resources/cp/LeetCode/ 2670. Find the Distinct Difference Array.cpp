class Solution {
public:
    int distinct(std::vector<int> a)
    {
        std::sort(a.begin(), a.end());
        auto u = std::unique(a.begin(), a.end());
        return u - a.begin();
    }
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        std::vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int left, right;
            if (i == 0) {
                left = 1;
            } else {
                std::vector<int> pref;
                pref.insert(pref.end(), nums.begin(), nums.begin() + i + 1);
                left = distinct(pref);
            }
            if (i == nums.size() - 1) {
                right = 0;
            } else {
                std::vector<int> suf;
                suf.insert(suf.end(), nums.begin() + i + 1, nums.end());
                right = distinct(suf);
            }
            res.push_back(left - right);
        }
        return res;
    }
};