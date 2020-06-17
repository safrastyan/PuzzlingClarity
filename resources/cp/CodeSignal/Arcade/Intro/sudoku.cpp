bool check(std::vector<int>& a)
{
    for (int i = 1; i <= 9; ++i) {
        if (std::find(a.begin(), a.end(), i) == a.end()) {
            return false;
        }
    }
    return true;
}

bool sudoku(std::vector<std::vector<int>> grid) 
{
    /// rows
    for (auto& v: grid) {
        if (!check(v)) {
            return false;
        }
    }    
    
    ///columns
    for (int i = 0; i < grid.size(); ++i) {
        std::vector<int> cur;
        for (int j = 0; j < grid.size(); ++j) {
            cur.push_back(grid[j][i]);
        }
        if (!check(cur)) {
            return false;
        }
    }
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::vector<int> cur;
            for (int ii = i * 3; ii < (i + 1) * 3; ++ii) {
                for (int jj = j * 3; jj < (j + 1) * 3; ++jj) {
                    cur.push_back(grid[ii][jj]);
                }
            }
            if (!check(cur)) {
                return false;
            }
        }
    }
    
    return true;
}
