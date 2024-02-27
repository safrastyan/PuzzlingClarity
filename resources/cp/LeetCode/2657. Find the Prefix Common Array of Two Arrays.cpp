class Solution {
public:

    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        std::vector<int> res;
        int n = A.size();
        for (int i = 0; i < n; ++i) {
            int common = 0;
            for (int j = 0; j <= i; ++j) {
                common += std::find(B.begin(), B.begin() + i + 1, A[j]) != B.begin() + i + 1 ? 1 : 0;
            }
            res.push_back(common);
        }
        return res;
    }
};