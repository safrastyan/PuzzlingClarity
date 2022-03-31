class Solution {
public:
    int jump(vector<int>& nums) 
    {
        std::vector<char> mark(nums.size(), 0);
        std::queue<std::pair<int, int>> q;
        
        mark[0] = 1;
        q.push(std::make_pair(0, 0));
        
        while (!q.empty()) {
            int location = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (location == nums.size() - 1) {
                return dist;
            }
            
            for (int i = 1; i <= nums[location]; ++i) {
                int new_location = location + i;
                if (new_location < nums.size() && mark[new_location] == 0) {
                    mark[new_location] = 1;
                    q.push(std::make_pair(new_location, dist + 1));
                }
            }
        }
        return -1;
    }
};