class Solution {
public:
    int dist(int x1, int y1, int x2, int y2)
    {
        return std::max(std::abs(x1 - x2), std::abs(y1 - y2));
    }
    
    int minTimeToVisitAllPoints(vector<vector<int>>& points) 
    {
        int res = 0;
        for (int i = 0; i < points.size() - 1; ++i) {
            res += dist(points[i][0], points[i][1], points[i + 1][0], points[i + 1][1]);
        }
        return res;
    }
};