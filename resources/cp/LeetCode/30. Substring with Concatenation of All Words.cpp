class Solution {
public:
    
    bool check(const std::string& s, int index, const std::unordered_map<std::string, int>& words, int length, int word_count)
    {
        auto m = words;
        for (int i = 0; i < word_count; ++i) {
            std::string temp = s.substr(index + i * length, length);
            auto f = m.find(temp);
            if (f == m.end() || f->second == 0) {
                return false;
            }
            --f->second;
        }
        return true;
    }
    
    
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        std::vector<int> res;
        std::unordered_map<std::string, int> m;
        for (auto& w: words) {
            ++m[w];
        }
        
        for (int i = 0; i < s.size() - words.size() * words[0].size() + 1; ++i) {
            if (check(s, i, m, words[0].size(), words.size())) {
                res.push_back(i);
            }
        }
        return res;
    }
};