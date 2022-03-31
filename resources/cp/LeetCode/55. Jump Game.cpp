class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
        std::vector<char> mark(nums.size(), 0);
        mark[0] = 1;
        std::queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int x = q.front();
            if (x == nums.size() - 1) {
                return true;
            }
            q.pop();
            for (int i = nums[x]; i >= 0; --i) {
                int new_x = x + i;
                if (new_x < nums.size() && mark[new_x] == 0) {
                    mark[new_x] = 1;
                    q.push(new_x);
                }
            }
        }
        return false;
    }
};