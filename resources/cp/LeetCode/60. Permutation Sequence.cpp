class Solution {
public:
    string getPermutation(int n, int k) 
    {
        std::string s;
        for (int i = 0; i < n; ++i) {
            s.push_back('0' + i + 1);
        }
        for (int i = 0; i < k - 1; ++i) {
            std::next_permutation(s.begin(), s.end());
        }
        return s;
    }
    
};