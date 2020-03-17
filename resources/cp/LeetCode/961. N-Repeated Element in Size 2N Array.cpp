class Solution {
public:
    
    int repeatedNTimes(vector<int>& A) 
    {
        vector<bool> m(10000, false);
        for (int i = 0; i < A.size(); ++i) {
            if (m[A[i]]) {
                return A[i];
            }
            m[A[i]] = true;
        }
        return A[0];
    }
};