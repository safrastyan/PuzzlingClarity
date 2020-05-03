class Solution {
public:
    
    void inc_row(std::vector<std::vector<int>>& a, int i)
    {
        for (int j = 0; j < a[0].size(); ++j) {
            ++a[i][j];
        }
    }
    
    void inc_col(std::vector<std::vector<int>>& a, int i)
    {
        for (int j = 0; j < a.size(); ++j) {
            ++a[j][i];
        }
    }
    
    int oddCells(int n, int m, vector<vector<int>>& indices) 
    {
        int res = 0;
        
        std::vector<std::vector<int>> a(n, std::vector<int>(m, 0));
        
        for (auto& p: indices) {
            inc_row(a, p[0]);
            inc_col(a, p[1]);
        }
        
        for (auto& v: a) {
            for (auto& elem: v) {
                if ( % 2 != 0) {
                    ++res;
                }
            }
        }
        return res;
        
    }
};