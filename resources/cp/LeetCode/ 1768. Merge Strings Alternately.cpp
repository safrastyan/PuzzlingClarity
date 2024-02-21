class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        if (word2.size() < word1.size()) {
            int d = word2.size() - word1.size();
            std::string tail = word1.substr(word2.size(), d);
            word1.erase(word2.size(), d);
            word2 += tail;
        }
        
        std::string res;
        for (int i = 0 ; i < word1.size(); ++i) {
            res.push_back(word1[i]);
            res.push_back(word2[i]);
        }
        return res + word2.substr(word1.size(), word2.size() - word1.size());
    }
};