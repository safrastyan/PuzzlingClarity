class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        std::vector<int> a(60);
        for (auto t: time) {
            ans += a[(60 - (t % 60))%60];
            ++a[t % 60];
        }
        return ans;
    }
};