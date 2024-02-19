class Solution {
public:
    int ind(const std::string& key)
    {
        if (key == "type") {
            return 0;
        }
        if (key == "color") {
            return 1;
        }
        if (key == "name") {
            return 2;
        }
        return -1;
    }
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int ans = 0;
        for (const auto& i: items) {
            if (i[ind(ruleKey)] == ruleValue) {
                ++ans;
            }
        }
        return ans;
    }
};