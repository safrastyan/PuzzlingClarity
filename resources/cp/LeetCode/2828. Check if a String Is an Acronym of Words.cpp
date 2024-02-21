class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        std::string ac;
        for (const auto& w:words) {
            ac.push_back(w[0]);
        }
        return ac == s;
    }
};