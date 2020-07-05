class Solution {
public:
    std::vector<int> next(const std::vector<int>& cells)
    {
        std::vector<int> res(8, 0);
        for (int j = 1; j < 7; ++j) {
            if ( (cells[j - 1] == 0 && cells[j + 1] == 0) || (cells[j - 1] == 1 && cells[j + 1] == 1)) {
                res[j] = 1;
            } else {
                res[j] = 0;
            }
        }
        return res;
    }
    
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        auto cur = cells;
        std::vector<std::vector<int>> rep(14);
        for (int i = 1; i < 14; ++i) {
            auto temp = next(cur);
            rep[i] = temp;
            cur = temp;
        }
        rep[0] = next(cur);
        return rep[N % 14];
    }
};