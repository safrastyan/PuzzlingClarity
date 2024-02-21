class Solution {
public:
    std::vector<std::string> split(const std::string& s)
    {
        std::stringstream ss(s);
        std::vector<std::string> res;
        std::string word;
        while (ss >> word) {
            res.push_back(word);
        }
        return res;
    }

    string reverseWords(string s) {
        auto words = split(s);
        std::string res;
        for (auto& w: words) {
            std::reverse(w.begin(), w.end());
            res += w;
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};