class Solution {
public:
    int max_col(const std::vector<std::vector<int>>& a, int col)
    {
        int m = -1;
        for (int i = 0; i < a.size(); ++i) {
            m = std::max(m, a[i][col]);
        }
        return m;
    }
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != -1) {
                    continue;
                }
                matrix[i][j] = max_col(matrix, j);
            }
        }
        return matrix;
    }
};