class Solution {
public:
    
    void help(std::vector<std::vector<int>>& a, int r, int c)
    {
        for (int j = 0; j < a[0].size(); ++j) {
            a[r][j] = 0;
        }
        
        for (int i = 0; i < a.size(); ++i) {
            a[i][c] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) 
    {
        std::vector<std::pair<int, int>> zeros;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    zeros.push_back(std::make_pair(i, j));
                }
            }
        }
        for (auto z: zeros) {
            help(matrix, z.first, z.second);
        }
    }
};