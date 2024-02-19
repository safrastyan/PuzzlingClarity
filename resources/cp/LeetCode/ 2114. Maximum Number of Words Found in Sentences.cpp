class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for (const auto& s: sentences) {
            res = std::max(res, static_cast<int>(std::count(s.begin(), s.end(), ' ') + 1));
        }
        return res;
    }
};