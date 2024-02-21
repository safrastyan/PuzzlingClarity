class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < arr.size() - 2; ++i) {
            for (int j = i + 1; j < arr.size() - 1; ++j) {
                for (int k = j + 1; k < arr.size(); ++k) {
                    if (std::abs(arr[i] - arr[j]) > a) {
                        continue;
                    }
                    if (std::abs(arr[j] - arr[k]) > b) {
                        continue;
                    }
                    if (std::abs(arr[k] - arr[i]) > c) {
                        continue;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};