bool extract(std::vector<int>& counts, std::vector<std::vector<int>>& res)
{
    std::vector<int> cur;
    for (int i = 0; i < counts.size(); ++i) {
        if (counts[i] == 0) {
            continue;
        }
        --counts[i];
        cur.push_back(i);
    }
    if (cur.empty()) {
        return false;
    }
    res.push_back(cur);
    return true;
}
class Solution {
public:

    vector<vector<int>> findMatrix(vector<int>& nums) {
        std::vector<int> counts(210, 0);
        for (auto n: nums) {
            ++counts[n];
        } 
        std::vector<std::vector<int>> res;
        while (extract(counts, res)) {}
        return res;
    }
};