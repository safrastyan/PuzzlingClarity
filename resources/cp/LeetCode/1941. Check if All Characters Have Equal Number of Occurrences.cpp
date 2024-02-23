class Solution {
public:
    bool areOccurrencesEqual(string s) {
        std::vector<int> oc;
        for (auto c: s) {
            oc.push_back(std::count(s.begin(), s.end(), c));
        }
        for (int i = 0; i < oc.size() - 1; ++i) {
            if (oc[i] != oc[i + 1]) {
                return false;
            }
        }
        return true;
    }
};