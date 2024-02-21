class Solution {
public:

    int calc(int n, int row, int col, std::string s)
    {
        int res = 0;
        for (auto c: s) {
            switch(c) {
            case 'L':
                --col;
                break;
            case 'R':
                ++col;
                break;
            case 'U':
                --row;
                break;
            case 'D':
                ++row;
                break;
            }
            if (col < 0 || row < 0 || col >= n || row >= n) {
                return res;
            }
            ++res;
        }
        return res;
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        std::vector<int> res;
        for (int i = 0; i < s.size(); ++i) {
            res.push_back(calc(n, startPos[0], startPos[1], s.substr(i, s.size() - i)));
        }
        return res;
    }
};