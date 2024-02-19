class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::vector<int> n, p;
        for (auto num: nums) {
            if (num < 0) {
                n.push_back(num);
                continue;
            }
            p.push_back(num);
        }
        std::vector<int> res;
        for (int i = 0; i < nums.size() / 2; ++i) {
            res.push_back(p[i]);
            res.push_back(n[i]);
        }
        return res;
    }
};