class Solution {
public:

    std::vector<int> extract(const std::vector<std::vector<int>>& a, int x, int y)
    {
        std::vector<int> res;
        while (x < a.size() && y < a[0].size()) {
            res.push_back(a[x][y]);
            ++x;
            ++y;
        }
        return res;
    }

    void embed(std::vector<std::vector<int>>& a, int x, int y, const std::vector<int>& elems)
    {
        for (auto e: elems) {
            a[x][y] = e;
            ++x;
            ++y;
        }
    }

    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for (int i = mat.size() - 1; i >= 0; --i) {
            auto e = extract(mat, i, 0);
            std::sort(e.begin(), e.end());
            embed(mat, i, 0, e);
        }
        for (int j = 1; j < mat[0].size(); ++j) {
            auto e = extract(mat, 0, j);
            std::sort(e.begin(), e.end());
            embed(mat, 0, j, e);
        }
        return mat;
    }
};