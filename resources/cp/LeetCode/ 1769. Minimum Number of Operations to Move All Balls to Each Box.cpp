class Solution {
public:
    vector<int> minOperations(string boxes) {
        std::vector<int> res;
        for (int i = 0; i < boxes.size(); ++i) {
            int temp = 0;
            for (int j = 0; j < boxes.size(); ++j) {
                if (boxes[j] == '1') {
                    temp += std::abs(i - j);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};