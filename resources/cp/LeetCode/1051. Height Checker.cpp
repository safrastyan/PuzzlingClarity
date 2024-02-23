class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto real = heights;
        std::sort(real.begin(), real.end());
        int ans = 0;
        for (int i = 0; i < real.size(); ++i) {
            if (real[i] != heights[i]) {
                ++ans;
            }
        }
        return ans;
    }
};