int crossingSum(std::vector<std::vector<int>> matrix, int a, int b) 
{
    int sum = std::accumulate(matrix[a].begin(), matrix[a].end(), 0);
    for (int i = 0; i < matrix.size(); ++i) {
        sum += matrix[i][b];
    }
    return sum - matrix[a][b];
}
