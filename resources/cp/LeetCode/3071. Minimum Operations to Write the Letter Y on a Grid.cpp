class Solution {
public:
    
    bool is_y(int n, int r, int c)
    {
        if (r == c && r <= n / 2) {
            return true;
        }
        if (r == n - c - 1 && r <= n / 2) {
            return true;
        }
        if (c == n / 2 && r >= n / 2) {
            return true;
        }
        return false;
    }
    
    int check(const std::vector<std::vector<int>>& a, int y, int noty)
    {
        int ans = 0;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (is_y(a.size(), i, j)) {
                    ans += a[i][j] == y ? 0 : 1;
                    continue;
                }
                ans += a[i][j] == noty ? 0 : 1;
            }
        }
        return ans;
    }
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int ans = 1000000;
        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2; ++j) {
                if (i == j) {
                    continue;
                }
                ans = std::min(ans, check(grid, i, j));
            }
        }
        return ans;
                              
    }
};