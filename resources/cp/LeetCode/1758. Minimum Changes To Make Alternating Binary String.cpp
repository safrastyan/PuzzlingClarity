class Solution {
public:

    int hamming_distance(const std::string& s1, const std::string& s2)
    {
        assert(s1.size() == s2.size());
        int res = 0;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                ++res;
            }
        }
        return res;
    }

    int minOperations(string s) {
        std::string v1, v2;
        for (int i = 0; i < s.size(); ++i) {
            if (i % 2 == 0) {
                v1.push_back('0');
                v2.push_back('1');
                continue;
            }
            v1.push_back('1');
            v2.push_back('0');
        }
        return std::min(hamming_distance(s, v1), hamming_distance(s, v2));
    }
};