class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        for (auto p: position) {
            if (p % 2 == 0) {
                ++even;
            }
        }
        return std::min(even, int(position.size()) - even);
    }
};