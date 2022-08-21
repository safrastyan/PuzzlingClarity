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
        std::sort(res.begin(), res.end());
        return res;
    }
    
    
    struct VecH
    {
        size_t operator()(const std::vector<int>& v) const{
            static int base = 1999;
            size_t x = base;
            size_t res = 1;
            for (auto vv: v) {
                res += x * vv;
                x *= base;
            }
            return res;
        }
    };
 
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        std::unordered_set<std::vector<int>, VecH> all;
        std::vector<std::vector<int>> res;
        for (int i = 0; i < 1 << nums.size(); ++i) {
            all.insert(mask(nums, i));
        }
        for (auto it = all.begin(); it != all.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }
};