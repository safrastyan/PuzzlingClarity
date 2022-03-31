class Solution {
public:
    
    void transpose(vector<vector<int>>& a)
    {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = i + 1; j < a.size(); ++j) {
                std::swap(a[i][j], a[j][i]);
            }
        }
    }
    
    void reverse(vector<vector<int>>& a)
    {
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size() / 2; ++j) {
                std::swap(a[i][j], a[i][a.size() - j - 1]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) 
    {
        transpose(matrix);
        reverse(matrix);
    }
};