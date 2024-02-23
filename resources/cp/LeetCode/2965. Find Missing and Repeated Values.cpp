class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int dub = -1;
        int mis = -1;
        int n = grid.size();
        int m = grid[0].size();
        std::vector<char> mark(n * m + 1, 0);
        for (const auto& row: grid) {
            for (auto elem: row) {
                if (mark[elem] == 0) {
                    mark[elem] = 1;
                    continue;
                }
                dub = elem;
            }
        }
        mis = std::find(mark.begin() + 1, mark.end(), 0) - mark.begin();
        return std::vector{dub, mis};
    }
};