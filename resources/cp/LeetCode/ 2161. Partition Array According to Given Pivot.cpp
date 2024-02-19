class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        std::vector<int> left, right;
        int piv = 0;
        for (auto n: nums) {
            if (n < pivot) {
                left.push_back(n);
                continue;
            }
            if (n == pivot) {
                ++piv;
                continue;
            }
            right.push_back(n);
        }
        std::vector<int> pp(piv, pivot);
        left.insert(left.end(), pp.begin(), pp.end());
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};