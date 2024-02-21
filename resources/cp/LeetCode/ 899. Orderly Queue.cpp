class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            std::sort(s.begin(), s.end());
            return s;
        }
        
        std::string ans = s;
        for (int i = 0; i < s.size(); ++i) {
            auto c = s[0];
            s.erase(0, 1);
            s.push_back(c);
            ans = std::min(ans, s);
        }
        return ans;

    }
};