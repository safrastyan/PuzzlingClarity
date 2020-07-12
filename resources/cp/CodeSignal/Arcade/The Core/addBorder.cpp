std::vector<std::string> addBorder(std::vector<std::string> picture) 
{
    int n = picture.size() + 2;
    int m = picture[0].size() + 2;
    std::vector<std::string> res(n, std::string(m, '*'));
    for (int i = 0; i < picture.size(); ++i) {
        for (int j = 0; j < picture[0].size(); ++j) {
            res[i + 1][j + 1] = picture[i][j];
        }
    }    
    return res;
}
