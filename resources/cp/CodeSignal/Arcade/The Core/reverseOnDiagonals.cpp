std::vector<std::vector<int>> reverseOnDiagonals(std::vector<std::vector<int>> matrix) 
{
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
        std::swap(matrix[i][i], matrix[n - i - 1][n - i -1]);
        std::swap(matrix[i][n - i - 1], matrix[n - i - 1][i]);
    }
    return matrix;
}
