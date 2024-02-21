class Solution {
public:
    int countTestedDevices(vector<int>& a) {
        int ans = 0;
        int c = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] <= c) {
                continue;
            }
            ++c;
            ++ans;
        }
        return ans;
    }
};