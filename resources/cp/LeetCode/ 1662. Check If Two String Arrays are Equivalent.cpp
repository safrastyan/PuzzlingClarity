class Solution {
public:
    std::string conc(const std::vector<std::string>& a)
    {
        std::string res;
        for (auto elem: a) {
            res += elem;
        }
        return res;
    }

    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        return conc(word1) == conc(word2);
    }
};