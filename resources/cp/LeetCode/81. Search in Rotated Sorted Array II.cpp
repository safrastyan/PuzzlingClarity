class Solution {
public:
    bool search(vector<int>& a, int target) {
        int k = a.size() - 1;
        for (int i = 0; i < a.size() - 1; ++i) {
            if (a[i] > a[i + 1]) {
                k = i + 1;
            }
        }
        return std::binary_search(a.begin(), a.begin() + k, target) || std::binary_search(a.begin() + k, a.end(), target);
    }
};