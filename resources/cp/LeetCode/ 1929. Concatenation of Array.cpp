class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> res;
        res.insert(res.begin(), nums.begin(), nums.end());
        res.insert(res.end(), nums.begin(), nums.end());
        return res;
    }
};