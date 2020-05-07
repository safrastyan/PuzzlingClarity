std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) 
{
    int px[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int py[] = {0, 1, 1, 1, 0, -1, -1, -1};
    std::vector<std::vector<int>> res(matrix.size(), std::vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            for (int k = 0; k < 8; ++k) {
                int new_i = i + px[k];
                int new_j = j + py[k];
                if (new_i >= 0 && new_i < matrix.size() && new_j >= 0 && new_j < matrix[0].size() && matrix[new_i][new_j]) {
                    ++res[i][j];
                }
            }
        }
    }
    return res;
}
