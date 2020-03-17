class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) 
    {
        std::vector<int> evens, odds;
        for (int i = 0; i < A.size(); ++i) {
            if (A[i] % 2 == 0) {
                evens.push_back(A[i]);
            } else {
                odds.push_back(A[i]);
            }
        }
        evens.insert(evens.end(), odds.begin(), odds.end());
        return evens;
    }
};