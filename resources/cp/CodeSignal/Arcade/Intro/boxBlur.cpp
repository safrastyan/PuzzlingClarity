std::vector<std::vector<int>> boxBlur(std::vector<std::vector<int>> image) 
{
    int n = image.size();
    int m = image[0].size();
    std::vector<std::vector<int>> res(n - 2, std::vector<int>(m - 2, 0));
    int px[] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int py[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            int sum = image[i][j];
            for (int k = 0; k < 8; ++k) {
                sum += image[i + px[k]][j + py[k]];
            }
            res[i - 1][j - 1] = sum / 9;
        }
    }
    return res;
}
