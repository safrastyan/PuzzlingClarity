class Solution {
public:
    
    void rec(const std::vector<int>& src, int pos, std::vector<int>& cur, int k, std::vector<std::vector<int>>& res)
    {
        if (cur.size() == k) {
            res.push_back(cur);
            return;
        }
        
        if (pos == src.size()) {
            return;
        }
        for (int i = pos; i < src.size(); ++i) {
            cur.push_back(src[i]);
            rec(src, i + 1, cur, k, res);
            cur.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> src;
        for (int i = 1; i <= n; ++i) {
            src.push_back(i);
        }
        
        std::vector<std::vector<int>> res;
        std::vector<int> cur;
        rec(src, 0, cur, k, res);
        return res;
    }
};