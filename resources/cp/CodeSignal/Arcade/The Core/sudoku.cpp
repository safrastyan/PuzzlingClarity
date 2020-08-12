bool check(std::vector<int> a)
{
    std::sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != i + 1) {
            return false;
        }
    }
    return true;
}

bool sudoku(std::vector<std::vector<int>> grid) 
{
    /// rows
    for (auto elem: grid) {
        if (!check(elem)) {
            std::cout << "r";
            return false;
        }
    }
    
    /// cols
    for (int i = 0; i < grid.size(); ++i) {
        std::vector<int> temp;
        for (int j = 0; j < grid.size(); ++j) {
            temp.push_back(grid[j][i]);
        }
        if (!check(temp)) {
            return false;
        }
    }
    
    /// boxes 3x3
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::vector<int> temp;
            for (int ii = 0; ii < 3; ++ii) {
                for (int jj = 0; jj < 3; ++jj) {
                    temp.push_back(grid[i * 3 + ii][j * 3 + jj]);
                }
            }
            if (!check(temp)) {
                
            std::cout << "b";
                return false;
            }
        }
    }
    return true;
}
