class Solution {
public:
    
    std::vector<int> mask(const std::vector<int>& a, int n)
    {
        std::string s(a.size(), 0);
        int pos = 0;
        while (n != 0) {
            s[pos] = n % 2;
            n /= 2;
            ++pos;
        }
        std::vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 1) {
                res.push_back(a[i]);
            }
        }
        return res;
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        std::vector<std::vector<int>> res;
        for (int i = 0; i < 1 << nums.size(); ++i) {
            res.push_back(mask(nums, i));
        }
        return res;
    }
};