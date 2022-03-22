class Solution {
public:
    
    std::map<int, std::vector<int>> collect_indices(const std::vector<int>& nums)
    {
        std::map<int, std::vector<int>> res;
        for (int i = 0; i < nums.size(); ++i) {
            res[nums[i]].push_back(i);            
        }
        return res;
    }
    
    bool check(const std::vector<int>& data, int x, int y, int z)
    {
        for (auto e: data) {
            if (e != x && e != y && e != z) {
                return true;
            }
        }
        return false;
    } 
    
    std::set<std::vector<int>> solve(const std::vector<int>& nums, std::map<int, std::vector<int>>& m, int target)
    {
        std::set<std::vector<int>> res;
        for (int i = 0; i < nums.size() - 3; ++i) {
            for (int j = i + 1; j < nums.size() - 2; ++j) {
                for (int k = j + 1; k < nums.size() - 1; ++k) {
                    long long cur = static_cast<long long>(nums[i]) + nums[j] + nums[k];
                    int want = target - cur;
                    auto& indices = m[want];
                    
                    if (indices.size() > 3 || check(indices, i, j, k)) {
                        std::vector<int> potential{nums[i], nums[j], nums[k], want};
                        std::sort(potential.begin(), potential.end());
                        res.insert(potential);
                    }
                }
                while (j < nums.size() - 2 && nums[j] == nums[j] + 1) {
                    ++j;
                }
            }
            while (i < nums.size() - 3 && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return res;
    }
    
    std::vector<std::vector<int>> normalize(std::set<std::vector<int>>& s)
    {
        std::vector<std::vector<int>> res;
        for (auto& elem: s) {
            res.push_back(elem);
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        if (nums.size() < 4) {
            return std::vector<std::vector<int>>();
        }
        std::sort(nums.begin(), nums.end());
        auto all = collect_indices(nums);
        auto set_ans = solve(nums, all, target);
        return normalize(set_ans);
    }
};