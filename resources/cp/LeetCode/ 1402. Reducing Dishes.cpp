class Solution {
public:
    int maxSatisfaction(vector<int>& a) {
        std::sort(a.begin(), a.end());
        int best = 0;
        for (int i = 0; i < a.size(); ++i) {
            int cur = 0;
            for (int j = i; j < a.size();++j) {
                cur += (j - i + 1) * a[j];
            }
            best = std::max(best, cur);
        }
        return best;
        
    }
};