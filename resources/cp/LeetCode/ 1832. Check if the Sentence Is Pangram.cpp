class Solution {
public:
    bool checkIfPangram(string sentence) {
        int count = 0;
        std::vector<char> a(26, 0);
        for (auto c: sentence) {
            if (a[c - 'a'] == 0) {
                a[c - 'a'] = 1;
                ++count;
            }
        }
        return count == 26;
    }
};