class Solution {
public:
    
    
    
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                long long x1 = bottomLeft[i][0];
                long long y1 = bottomLeft[i][1];
                long long x2 = topRight[i][0];
                long long y2 = topRight[i][1];
                
                long long x3 = bottomLeft[j][0];
                long long y3 = bottomLeft[j][1];
                long long x4 = topRight[j][0];
                long long y4 = topRight[j][1];
                
                
                long long x5 = std::max(x1, x3);
                long long y5 = std::max(y1, y3);
                
                long long x6 = std::min(x2, x4);
                long long y6 = std::min(y2, y4);
                
                if (x5 <= x6 && y5 <= y6) {
                    long long dif = std::min(x6 - x5, y6 - y5);
                    ans = std::max(ans, dif * dif);
                }
            }
        }
        return ans;
    }
};