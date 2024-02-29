class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = 0;
        int p = 0;

        for (auto v: values) {
            ans = std::max(ans, v + p);
            p = std::max(p, v) - 1;
        }
        return ans;
    }
};