std::vector<int> extractMatrixColumn(std::vector<std::vector<int>> matrix, int column) 
{
    std::vector<int> res;
    for (int i = 0; i < matrix.size(); ++i) {
        res.push_back(matrix[i][column]);
    }
    return res;
}
