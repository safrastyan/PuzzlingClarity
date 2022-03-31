class Solution {
public:
    
    void rec(const std::vector<int>& candidates, int target, int cur_index, int cur_sum, std::vector<int>& cur_ans, std::vector<std::vector<int>>& res)
    {
        if (cur_index == candidates.size()) {
            return;
        }
        if (cur_sum == target) {
            res.push_back(cur_ans);
            return;
        }    
        if (cur_sum > target) {
            return;
        }
        
        cur_ans.push_back(candidates[cur_index]);
        rec(candidates, target, cur_index, cur_sum + candidates[cur_index], cur_ans, res);
        cur_ans.pop_back();
        rec(candidates, target, cur_index + 1, cur_sum, cur_ans, res);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        rec(candidates, target, 0, 0, cur, res);
        return res;
    }
};