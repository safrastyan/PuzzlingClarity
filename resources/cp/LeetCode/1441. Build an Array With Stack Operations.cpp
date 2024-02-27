class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        std::vector<std::string> res;
        
        for (int i = 0; i < target[0] - 1; ++i) {
            res.push_back("Push");
            res.push_back("Pop");
        }

        for (int i = 0; i < target.size() - 1; ++i) {
            res.push_back("Push");
            for (int j = 0; j < target[i + 1] - target[i] - 1; ++j) {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        res.push_back("Push");
        return res;
    }
};