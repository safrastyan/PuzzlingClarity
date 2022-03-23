class Solution {
public:
    
    bool check(const std::vector<int>& v)
    {
        auto a = v;
        std::sort(a.begin(), a.end());
        auto f = std::unique(a.begin(), a.end());
        return f == a.end();
    }
    
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; ++i) {
            std::vector<int> t;
            for (int j = 0; j < 9; ++j) {
                if (std::isdigit(board[i][j])) {
                    t.push_back(board[i][j] - '0');
                }
            }
            if (!check(t)) {
                return false;
            }
        }
        
        for (int i = 0; i < 9; ++i) {
            std::vector<int> t;
            for (int j = 0; j < 9; ++j) {
                if (std::isdigit(board[j][i])) {
                    t.push_back(board[j][i] - '0');
                }
            }
            if (!check(t)) {
                return false;
            }
        }
        
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::vector<int> t;
                for (int ii = i * 3; ii < (i + 1) * 3; ++ii) {
                    for (int jj = j * 3; jj < (j + 1) * 3; ++jj) {
                        if (std::isdigit(board[ii][jj])) {
                            t.push_back(board[ii][jj] - '0');
                        }
                    }
                }
                if (!check(t)) {
                    return false;
                }
            }
        }
        
        return true;
    }
};