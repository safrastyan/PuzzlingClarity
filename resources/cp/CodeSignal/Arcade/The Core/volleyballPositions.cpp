std::vector<std::vector<std::string>> volleyballPositions(std::vector<std::vector<std::string>> formation, int k) 
{
    std::map<std::pair<int,int>, std::pair<int, int>> m;
    m[std::make_pair(0, 1)] = std::make_pair(1, 0);
    m[std::make_pair(1, 2)] = std::make_pair(0, 1);
    m[std::make_pair(3, 2)] = std::make_pair(1, 2);
    m[std::make_pair(2, 1)] = std::make_pair(3, 2);
    m[std::make_pair(3, 0)] = std::make_pair(2, 1);
    m[std::make_pair(1, 0)] = std::make_pair(3, 0);
    for (int i = 0; i < k % 6; ++i) {
        auto temp = formation;
        for (auto elem: m) {
            auto src = elem.first;
            auto dest = elem.second;
            temp[dest.first][dest.second] = formation[src.first][src.second];
        }
        formation = temp;
    }
    return formation;
}
