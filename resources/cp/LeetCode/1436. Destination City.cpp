class Solution {
public:
    string destCity(vector<vector<string>>& paths) 
    {
        std::set<std::string> s;
        for (auto path: paths) {
            s.insert(path[0]);
        }
        for (auto path: paths) {
            for (auto name: path) {
                if (s.find(name) == s.end()) {
                    return name;
                }
            }
        }
        return "";
    }
};