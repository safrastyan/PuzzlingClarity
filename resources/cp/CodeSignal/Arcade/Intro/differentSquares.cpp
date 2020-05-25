int differentSquares(std::vector<std::vector<int>> matrix) 
{
    std::set<std::string> res;
    for (int i = 0; i < matrix.size() - 1; ++i) {
        for (int j = 0; j < matrix[i].size() - 1; ++j) {
            std::string square;
            square.push_back(matrix[i][j] + '0');
            square.push_back(matrix[i][j + 1] + '0');
            square.push_back(matrix[i + 1][j + 1] + '0');
            square.push_back(matrix[i + 1][j] + '0');
            res.insert(square);   
        }
    }
    return res.size();
}
