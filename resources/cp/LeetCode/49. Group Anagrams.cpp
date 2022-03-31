class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> m;
    
        for (auto s: strs) {
            auto key = s;
            std::sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        std::vector<std::vector<std::string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};