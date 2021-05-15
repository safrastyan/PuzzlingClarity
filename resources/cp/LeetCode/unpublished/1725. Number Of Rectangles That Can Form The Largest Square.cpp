class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        std::vector<int> all;
        for (auto& rect: rectangles) {
            all.push_back(std::min(rect[0], rect[1]));
        }
        auto m = *std::max_element(all.begin(), all.end());
        return std::count(all.begin(), all.end(), m);
    }
};