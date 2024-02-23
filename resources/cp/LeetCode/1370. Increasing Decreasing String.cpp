class Solution {
public:
    string sortString(string s) {
        std::vector<int> bucket(26, 0);
        for (auto c: s) {
            ++bucket[c - 'a'];
        }
        std::string res;
        int rem = s.size();
        bool inc = true;
        while (rem != 0) {
            for (int i = inc ? 0 : 25; inc ? i < 26 : i >= 0; inc ? ++i : --i) {
                if (bucket[i] != 0) {
                    --bucket[i];
                    --rem;
                    res.push_back(i + 'a');
                    if (rem == 0) {
                        return res;
                    }
                }
            }
            inc = !inc;
        }
        return res;
    }
};