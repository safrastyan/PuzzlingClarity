class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        std::vector<int> sq;
        for (auto r: rectangles) {
            sq.push_back(std::min(r[0], r[1]));
        }
        auto max = *std::max_element(sq.begin(), sq.end());
        return std::count(sq.begin(), sq.end(), max);
    }
};