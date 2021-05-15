class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int res = 0;
        for (int i = 0; i < mat.size(); ++i) {
            res += mat[i][i];
            res += mat[i][mat.size() - i - 1];
        }
        return res - (mat.size() % 2 == 0 ? 0 : mat[mat.size() / 2][mat.size() / 2]);
    }
};