class Solution {
public:
    int trap(vector<int>& height) 
    {
        std::vector<int> right(height.size(), 0);
        std::vector<int> left(height.size(), 0);
        
        int ans = 0;
        
        right[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            right[i] = std::max(height[i], right[i + 1]);
        }
        
        left[0] = height[0];
        for (int i = 1; i < height.size(); ++i) {
            left[i] = std::max(height[i], left[i - 1]);
        }
        
        for (int i = 1; i < height.size() - 1; ++i) {
            ans += std::min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};