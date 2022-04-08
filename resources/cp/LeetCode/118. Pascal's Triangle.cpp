class Solution {
public:
    
    std::vector<int> next(const std::vector<int>& a)
    {
        std::vector<int> res{1};
        for (int i = 0; i < a.size() - 1; ++i) {
            res.push_back(a[i] + a[i + 1]);
        }
        res.push_back(1);
        return res;
    }
    
    vector<vector<int>> generate(int numRows) 
    {
        std::vector<std::vector<int>> res;
        res.push_back(std::vector<int>{1});
        if (numRows == 1) {
            return res;
        }
        res.push_back(std::vector<int>{1, 1});
        for (int i = 3; i <= numRows; ++i) {
            res.push_back(next(res.back()));
        }
        return res;
    }
};