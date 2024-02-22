class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        auto cp = a;
        std::sort(a.begin(), a.end());
        auto u = std::unique(a.begin(), a.end());
        a.erase(u, a.end());
        
        std::set<int> counts;
        for (auto elem: a) {
            int cur_count = std::count(cp.begin(),cp.end(), elem);
            if (counts.find(cur_count) != counts.end()) {
                return false;
            }
            counts.insert(cur_count);
        }
        return true;
    }
};