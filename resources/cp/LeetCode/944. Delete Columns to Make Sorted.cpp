class Solution {
public:
    int minDeletionSize(vector<string>& A) 
    {
        int res = 0;
        for (int i = 0; i < A[0].size(); ++i) {
            
            bool is_bad = false;
            for (int j = 0; j < A.size() - 1; ++j) {
                if (A[j][i] > A[j + 1][i]) {
                    is_bad = true;
                    break;
                }
            }
            if (is_bad) {
                ++res;
            }
        }
        return res;
    }
};