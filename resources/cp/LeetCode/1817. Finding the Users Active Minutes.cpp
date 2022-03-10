class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) 
    {
        std::map<int, std::set<int>> m;
        for (auto e: logs) {
            m[e[0]].insert(e[1]);
        }
        std::vector<int> res(k, 0);
        for (auto e: m) {
            if (e.second.size() > k) {
                continue;
            }
            ++res[e.second.size() - 1];
        }
        return res;
    }
};