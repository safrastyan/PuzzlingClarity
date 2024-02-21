class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = i; j < arr.size(); ++j) {
                if ((j - i) % 2 == 1) {
                    continue;
                }
                ans += std::accumulate(arr.begin() + i, arr.begin() + j + 1, 0); 
            }
        }
        return ans;
    }
};