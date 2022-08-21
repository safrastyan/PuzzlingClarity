class Solution {
public:
    
    bool rec(std::vector<std::vector<char>>& a, std::vector<std::vector<char>>& mark, int r, int c, int len, const std::string& word)
    {
        if (len == word.size()) {
            return true;
        }
       
        static int px[] = {0, 0, 1, -1};
        static int py[] = {1, -1, 0, 0};
        bool ans = false;
        for (int i = 0; i < 4; ++i) {
            int nr = r + px[i];
            int nc = c + py[i];
            if (nr < 0 || nc < 0 || nr >= a.size() || nc >= a[0].size() || mark[nr][nc] == 1 || a[nr][nc] != word[len]) {
                continue;
            }
            mark[nr][nc] = true;
            ans |= rec(a, mark, nr, nc, len + 1, word);
            mark[nr][nc] = false;
        }
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] != word[0]) {
                    continue;
                }     
                
                std::vector<std::vector<char>> mark(board.size(), std::vector<char>(board[0].size(), 0));
                mark[i][j] = 1;
                if (rec(board, mark, i, j, 1, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};