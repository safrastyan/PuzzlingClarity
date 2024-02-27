class Solution {
public:
    string removeOccurrences(string s, string part) {
        int p = s.find(part);
        while (p != std::string::npos) {
            s.erase(p, part.size());
            p = s.find(part);
        }
        return s;
    }
};