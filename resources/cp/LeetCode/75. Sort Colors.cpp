class Solution {
public:
    void sortColors(vector<int>& nums) {
        std::vector<int> colors(3, 0);
        for (auto c: nums) {     
            ++colors[c];
        }
        int color = 0;
        int current = 0;
        for (int i = 0; i < nums.size(); ++i) {
            ++current;
            while (current > colors[color]) {
                ++color;
                current = 1;
            }
            nums[i] = color;
        }
    }
};