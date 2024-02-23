class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        std::vector<char> mark(200, 0);
        for (const auto& c: nums) {
            for (int i = c[0]; i <= c[1]; ++i) {
                mark[i] = 1;
            }
        }
        return std::count(mark.begin(), mark.end(), 1);
    }
};