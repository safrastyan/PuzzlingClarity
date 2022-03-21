class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size() - 1;
        int ans = std::min(height[left], height[right]) * (height.size() - 1);
        
        while (left < right) {
            int cur = std::min(height[left], height[right]) * (right - left);
            ans = std::max(cur, ans);
            if (height[left] < height[right]) {
                ++left;
                continue;
            }
            --right;
        }
        return ans;
    }
};