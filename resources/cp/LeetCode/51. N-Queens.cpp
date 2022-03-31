class Solution {
public:
    
    
    std::vector<std::string> draw(const std::vector<int>& a)
    {
        std::vector<std::string> board(a.size(), std::string(a.size(), '.'));
        for (int i = 0; i < a.size(); ++i) {
            board[i][a[i]] = 'Q';
        }
        return board;
    }
    
    bool check(const std::vector<std::string>& a, int r, int c, int dr, int dc)
    {
        if (r < 0 || c < 0 || r >= a.size() || c >= a.size()) {
            return true;
        }
        if (a[r][c] == 'Q') {
            return false;
        }
        return check(a, r + dr, c + dc, dr, dc);
    }
    
    bool check(const std::vector<std::string>& a)
    {
        static constexpr int dr[] = {1, 1, -1, -1};
        static constexpr int dc[] = {1, -1, 1, -1};
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                if (a[i][j] == '.') {
                    continue;
                }
                for (int k = 0; k < 4; ++k) {
                    if (!check(a, i + dr[k], j + dc[k], dr[k], dc[k])) {
                        return false;
                    }
                }
              
            }
        }
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        std::vector<std::vector<std::string>> res;
        
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
        
        while (true) {
            auto board = draw(a);
            if (check(board)) {
                res.push_back(board);
            }
            if (!std::next_permutation(a.begin(), a.end())) {
                break;
            }
        }
        
        return res;
    }
};