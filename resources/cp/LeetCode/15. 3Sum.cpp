class Solution {
public:
    
    std::set<std::vector<int>> collect(const std::vector<int>& a)
    {
        std::set<vector<int>> all;
        for (int i = 0; i < a.size() - 2; ++i) {
            int target = -a[i];
            int left = i + 1;
            int right = a.size() - 1;
            while (left < right) {
                if (a[left] + a[right] == target) {
                   all.insert(std::vector<int>{a[i], a[left], a[right]}); 
                }
                if (a[left] + a[right] > target) {
                    --right;
                    continue;
                }
                ++left;
            }
            
            while (i < a.size() - 2 && a[i] == a[i + 1]) {
                ++i;
            }
        }
        return all;
    }
    
    std::vector<std::vector<int>> normalize(const std::set<std::vector<int>>& all)
    {
        std::vector<std::vector<int>> res;
        for (auto elem: all) {
            res.push_back(elem);
        }
        return res;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        if (nums.size() <= 2) {
            return std::vector<std::vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        auto all = collect(nums);
        return normalize(all);
    }
};