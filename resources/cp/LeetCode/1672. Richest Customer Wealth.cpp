class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int best = 0;
        for (const auto& a: accounts) {
            best = std::max(best, std::accumulate(a.begin(), a.end(), 0));
        }
        return best;
    }
};