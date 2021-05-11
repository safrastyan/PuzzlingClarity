class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> mark(n, 0);
        for (auto& elem: edges) {
            mark[elem[1]] = 1;
        }
        std::vector<int> res;
        for (int i = 0; i < mark.size(); ++i) {
            if (mark[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};