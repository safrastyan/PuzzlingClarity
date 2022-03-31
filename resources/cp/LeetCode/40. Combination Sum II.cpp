class Solution {
public:
    
    int next(const std::vector<int>& candidates, int i)
    {
        int cur = candidates[i];
        while (i < candidates.size() && candidates[i] == cur) {
            ++i;
        }
        return i;
    }
    
    void rec(const std::vector<int>& candidates, int target, int cur_index, int cur_sum, std::vector<int>& cur_ans, std::vector<std::vector<int>>& res)
    {
        if (cur_sum == target) {
            res.push_back(cur_ans);
            return;
        }
        if (cur_sum > target || cur_index == candidates.size()) {
            return;
        }
        
        int n = candidates[cur_index];
        cur_ans.push_back(n);
        rec(candidates, target, cur_index + 1, cur_sum + n, cur_ans, res);
        cur_ans.pop_back();
        rec(candidates, target, next(candidates, cur_index), cur_sum, cur_ans, res);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        std::sort(candidates.begin(), candidates.end());
        rec(candidates, target, 0, 0, cur, res);
        return res;
    }
    
};