class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans = 0;
        while (!grid[0].empty()) {
            int b = 0;
            for (int i = 0; i < grid.size(); ++i) {
                auto m = std::max_element(grid[i].begin(), grid[i].end());
                b = std::max(b, *m);
                grid[i].erase(m);
            }
            ans += b;
        }
        return ans;
    }
};