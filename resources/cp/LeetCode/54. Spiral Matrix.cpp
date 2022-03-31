class Solution {
public:
    
    static constexpr int V = 100000;
    
    bool is_valid(const std::vector<std::vector<int>>& a, int r, int c)
    {
        return r >= 0 && c >= 0 && r < a.size() && c < a[0].size() && a[r][c] != V;
    }
    
    void rec(std::vector<std::vector<int>>& a, int r, int c, int dir_ind, std::vector<int>& res)
    {
        if (a[r][c] == V) {
            return;
        }
        static constexpr int dr[] = {0, 1, 0, -1};
        static constexpr int dc[] = {1, 0, -1, 0};
        res.push_back(a[r][c]);
        a[r][c] = V;
        
        if (!is_valid(a, r + dr[dir_ind], c + dc[dir_ind])) {
            dir_ind += 1;
            if (dir_ind >= 4) {
                dir_ind = 0;
            }
        }
        rec(a, r + dr[dir_ind], c + dc[dir_ind], dir_ind, res);
    }
        
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.size() == 1) {
            return matrix[0];
        }
        if (matrix[0].size() == 1) {
            std::vector<int> res;
            for (int i = 0; i < matrix.size(); ++i) {
                res.push_back(matrix[i][0]);
            }
            return res;
        }
        std::vector<int> res;
        rec(matrix, 0, 0, 0, res); 
        return res;
    }
};