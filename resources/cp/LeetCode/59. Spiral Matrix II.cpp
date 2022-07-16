class Solution {
public:
    
    bool valid(const std::vector<std::vector<int>>& a, int r, int c)
    {
        return r >= 0 && r < a.size() && c >= 0 && c < a.size() && a[r][c] == 0;
    }
    
    void flip(int& dirr, int& dirc)
    {
        if (dirr == 0 && dirc == 1) {
            dirr = 1;
            dirc = 0;
            return;
        }
        if (dirr == 1 && dirc == 0) {
            dirr = 0;
            dirc = -1;
            return;
        }
        if (dirr == 0 && dirc == -1) {
            dirr = -1;
            dirc = 0;
            return;
        }
        dirr = 0;
        dirc = 1;
    }
    
    void rec(std::vector<std::vector<int>>& a, int r, int c, int cur, int dirr, int dirc)
    {
        a[r][c] = cur;
        if (cur == a.size() * a.size()) {
            return;
        }
        int newr = r + dirr;
        int newc = c + dirc;
        if (valid(a, newr, newc)) {
            rec(a, newr, newc, cur + 1, dirr, dirc);
            return;
        }
        flip(dirr, dirc);
        rec(a, r + dirr, c + dirc, cur + 1, dirr, dirc);
        
    }
    
    vector<vector<int>> generateMatrix(int n) 
    {
        std::vector<std::vector<int>> a(n, std::vector<int>(n, 0));
        rec(a, 0 , 0, 1, 0, 1);
        return a;
        
    }
};