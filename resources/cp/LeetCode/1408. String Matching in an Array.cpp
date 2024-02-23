class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::vector<std::string> ans;
        for (int i = 0; i < words.size() - 1; ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (words[j].find(words[i]) == std::string::npos) {
                    continue;
                }
                ans.push_back(words[i]);
                break;
            }
        }
        return ans;
    }

};