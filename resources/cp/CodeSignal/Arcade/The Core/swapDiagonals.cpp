std::vector<std::vector<int>> swapDiagonals(std::vector<std::vector<int>> matrix) 
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        std::swap(matrix[i][i], matrix[i][n - i - 1]);
    }
    return matrix;
}
