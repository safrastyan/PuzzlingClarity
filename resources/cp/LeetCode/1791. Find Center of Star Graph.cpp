class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        std::vector<char> mark(edges.size() + 2, 0);
        for (const auto& e: edges) {
            if (mark[e[0]] == 1) {
                return e[0];
            }
            mark[e[0]] = 1;
            if (mark[e[1]] == 1) {
                return e[1];
            }
            mark[e[1]] = 1;
        }
        return 0;
    }
};