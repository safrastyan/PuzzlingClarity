class Solution {
public:
    string decodeMessage(string key, string message) {
        std::vector<char> a(27, 0);
        int x = 0;
        for (int i = 0; x < 26; ++i) {
            if (std::isalpha(key[i]) && a[key[i] - 'a'] != 0) {
                a[key[i] - 'a'] = 'a' + x;
                ++x;
            }
        }
        for (auto& c: message) {
            if (!std::isalpha(c)) {
                continue;
            }
            c = a[c - 'a'];
        } 
        
        return message;
    }
};