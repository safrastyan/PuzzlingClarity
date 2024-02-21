class Solution {
public:
    string finalString(string s) {
        std::string res;
        for (auto c: s) {
            if (c == 'i') {
                std::reverse(res.begin(), res.end());
                continue;
            }
            res.push_back(c);
        }
        return res;
    }
};