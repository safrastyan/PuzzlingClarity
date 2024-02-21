class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int s = 0;
        int best = 0;
        for (int i = 0; i < gain.size(); ++i) {
            s += gain[i];
            best = std::max(best, s);
        }
        return best;
    }
};