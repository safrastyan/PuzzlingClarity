class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int r = -1;
        int best = -1;
        for (int i = 0; i < mat.size(); ++i) {
            auto c = std::count(mat[i].begin(), mat[i].end(), 1);
            if (c > best) {
                best = c;
                r = i;
            }
        }
        return std::vector<int>{r, best};
    }
};