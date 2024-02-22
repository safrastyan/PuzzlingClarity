class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = std::count(s.begin(), s.end(), '1');
        int zer = s.size() - ones;
        return std::string(ones - 1, '1') + std::string(zer, '0') + "1";
    }
};