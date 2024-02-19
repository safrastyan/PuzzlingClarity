bool operator < (const std::vector<int>& a, const std::vector<int>& b)
{
    return a[0] < a[1];
}
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end());
        int best = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            best = std::max(best, points[i + 1][0] - points[i][0]);
        }
        return best;
    }
};