

std::vector<std::vector<int>> apply(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<std::pair<int, int>>>& map)
{
    auto res = matrix;
    for (int i = 0; i < map.size(); ++i) {
        for (int j = 0; j < map[0].size(); ++j) {
            auto dst = map[i][j];
            res[dst.first][dst.second] = matrix[i][j];
        }
    }
    
    return res;    
}

std::vector<std::vector<int>> starRotation(std::vector<std::vector<int>> matrix, int width, std::vector<int> center, int t) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    std::vector<std::vector<std::pair<int, int>>> map(n, std::vector<std::pair<int, int>>(m));
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            map[i][j] = std::make_pair(i, j);
        }
    }
    int cx = center[0];
    int cy = center[1];
    int half = width / 2;
    for (int i = 0; i < half; ++i) {
        map[cx - half + i][cy] = std::make_pair(cx - half + i, cy + half - i);/// north
        map[cx - half + i][cy + half - i] = std::make_pair(cx, cy + half - i);/// north east
        map[cx][cy + half - i] = std::make_pair(cx + half - i, cy + half - i);/// east
        map[cx + half - i][cy + half - i] = std::make_pair(cx + half - i, cy);/// south east
        map[cx + half - i][cy] = std::make_pair(cx + half - i, cy - half + i);/// south
        map[cx + half - i][cy - half + i] = std::make_pair(cx, cy - half + i);/// south west
        map[cx][cy - half + i] = std::make_pair(cx - half + i, cy - half + i);/// west
        map[cx - half + i][cy - half + i] = std::make_pair(cx - half + i, cy);/// north west
    }
    
    for (int i = 0; i < t % 8; ++i) {
        matrix = apply(matrix, map);
    }
    return matrix;
}
