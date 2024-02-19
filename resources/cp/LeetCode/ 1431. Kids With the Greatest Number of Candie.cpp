class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        std::vector<bool> res;
        int m = *std::max_element(candies.begin(), candies.end());
        for (auto c: candies) {
            res.push_back(c + extraCandies >= m);
        }
        return res;
    }
};