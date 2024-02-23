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
    int isPrefixOfWord(string sentence, string searchWord) {
        auto words = split(sentence);
        for (int i = 0; i < words.size(); ++i){
            if (words[i].find(searchWord) == 0) {
                return i + 1;
            }
        }
        return -1;
    }
};