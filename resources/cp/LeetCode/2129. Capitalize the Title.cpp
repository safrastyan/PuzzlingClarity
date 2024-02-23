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

    string capitalizeTitle(string title) {
        auto words = split(title);
        std::string res;
        for (auto w: words) {
            std::transform(w.begin(), w.end(), w.begin(), ::tolower);
            if (w.size() > 2) {
                w[0] = std::toupper(w[0]);
            }
            res += w;
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};