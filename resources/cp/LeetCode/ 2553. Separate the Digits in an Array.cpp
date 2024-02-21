class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        std::vector<int> ans;
        for (auto n: nums) {
            std::vector<int> temp;
            while (n != 0) {
                temp.push_back(n % 10);
                n /= 10;
            }
            std::reverse(temp.begin(), temp.end());
            ans.insert(ans.end(), temp.begin(), temp.end());
        }
        return ans;
    }
};