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
    
    vector<int> getRow(int rowIndex) 
    {
        if (rowIndex <= 1) {
            return std::vector<int>(rowIndex + 1, 1);
        }
        std::vector<int> res{1, 1};
        for (int i = 2; i <= rowIndex; ++i) {
            res = next(res);
        }
        return res;
    }
};