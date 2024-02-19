class Solution {
public:
    vector<string> cellsInRange(string s) {
        std::vector<std::string> res;
        for (auto i = s[0]; i <= s[3]; ++i) {
            for (auto j = s[1]; j <= s[4]; ++j) {
                res.push_back(std::string{i, j});
            }
        }
        return res;
    }
};