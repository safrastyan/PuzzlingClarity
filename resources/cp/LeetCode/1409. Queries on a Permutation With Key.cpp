class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        std::vector<int> res;
        
        std::vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            a[i] = i + 1;
        }
        
        for (auto q: queries) {
            auto f = std::find(a.begin(), a.end(), q);
            res.push_back(f - a.begin());
            a.erase(f);
            a.insert(a.begin(), q);
        }
        return res;
    }
};