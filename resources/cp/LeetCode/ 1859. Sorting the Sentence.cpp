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

    string sortSentence(string s) {
        auto words = split(s);
        std::string ans;
        for (int i = 1; i <= words.size(); ++i) {
            for (int j = 0; j < words.size(); ++j) {
                if (words[j].find(std::to_string(i)) == -1) {
                    continue;
                }
                ans += words[j];
                ans.pop_back();
                ans.push_back(' ');
            }
        }
        ans.pop_back();
        return ans;
    }
};