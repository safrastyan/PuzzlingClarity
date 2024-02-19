class Solution {
public:
    int dist(int x1, int y1, int x2, int y2) {
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    }
    bool check(int x0, int y0, int r, int x, int y)
    {   
        int d = dist(x0, y0, x, y);
        return d <= r * r;
    }

    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        std::vector<int> res;
        for (const auto& q: queries) {
            int c = 0;
            for (const auto& p: points) {
                if (!check(q[0], q[1], q[2], p[0], p[1])) {
                    continue;
                }
                ++c;
            }
            res.push_back(c);
        }
        return res;
    }
};