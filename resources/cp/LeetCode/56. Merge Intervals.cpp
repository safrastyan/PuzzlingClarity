bool operator < (const std::vector<int>& a, const std::vector<int>& b)
{
    if (a[0] < b[0]) {
        return true;
    }
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return false;
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> res;
        
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
                continue;
            }
            res.push_back(intervals[i]);
        }
        return res;
    }
};