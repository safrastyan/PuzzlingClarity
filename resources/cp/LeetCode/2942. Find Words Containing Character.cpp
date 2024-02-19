class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        std::vector<int> res;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i].find(x) == -1) {
                continue;
            }
            res.push_back(i);
        }
        return res;
    }
};