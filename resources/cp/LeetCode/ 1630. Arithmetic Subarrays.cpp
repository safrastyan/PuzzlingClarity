class Solution {
public:
    bool check(const std::vector<int>& a)
    {
        int d = a[1] - a[0];
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i + 1] - a[i] != d) {
                return false;
            }
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        std::vector<bool> ans;
        for (int i = 0; i < l.size(); ++i) {
            std::vector<int> cut;
            cut.insert(cut.end(), nums.begin() + l[i], nums.begin() + r[i] + 1);
            std::sort(cut.begin(), cut.end());
            ans.push_back(check(cut));
        }
        return ans;
    }
};