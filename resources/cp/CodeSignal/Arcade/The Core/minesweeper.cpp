std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) 
{
    std::vector<std::vector<int>> res(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    int px[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int py[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int k = 0; k < 8; ++k) {
                int x = i + px[k];
                int y = j + py[k];
                if (x >= 0 && x < matrix.size() && y >= 0 && y < matrix[0].size() && matrix[x][y]) {
                    ++res[i][j];
                } 
            }
        }
    } 
    return res;
}
