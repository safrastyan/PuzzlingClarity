class Solution {
public:
    
    void change_direction(int& pr, int& pc)
    {
        if (pc == 0) {
            pr = -1;
            pc = 1;
            return;
        }
        pr = 1;
        pc = 0;
    }
    
    string convert(string s, int numRows) 
    {
        if (numRows == 1) {
            return s;
        }
        std::vector<std::string> a(numRows, std::string(1000, ' '));
        int r = 1, c = 0;
        int pr = 1, pc = 0;
        a[0][0] = s[0];
        for (int i = 1; i < s.size(); ++i) {
            a[r][c] = s[i];
            if (r == numRows - 1 || r == 0) {
                change_direction(pr, pc);
            } 
            r += pr;
            c += pc;
        }
        
        std::string res;
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[i].size(); ++j) {
                if (a[i][j] == ' ') {
                    continue;
                }
                res.push_back(a[i][j]);
            }
        }
        return res;
    }
};