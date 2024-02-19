class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long num = 1;
        int res = 0;
        for (int i = columnTitle.size() - 1; i >= 0; --i) {
            res += (columnTitle[i] - 'A' + 1) * num;
            num *= 26;
        }
        return res;
    }
};