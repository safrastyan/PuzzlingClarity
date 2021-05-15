class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        std::map<int, std::set<int>> all;
        for (auto& elem: logs) {
            all[elem[0]].insert(elem[1]);
        }
        std::vector<int> res(k, 0);
        for (auto& p: all) {
            if (p.second.size() > k) {
                continue;
            }
            ++res[p.second.size() - 1];
        }
        return res;
    }
};