class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0;
        for (const auto& o: operations) {
            res += o[1] == '+' ? 1 : -1;
        }
        return res;
    }
};