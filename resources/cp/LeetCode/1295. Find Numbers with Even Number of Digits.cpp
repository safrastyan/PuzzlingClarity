class Solution {
public:
    
    int num_digits(int n)
    {
        int count = 0;
        while (n != 0) {
            n /= 10;
            ++count;
        }
        return count;
    }
 
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for (auto elem: nums) {
            
            if (num_digits(elem) % 2 == 0) {
                ++res;
            }
        }
        return res;
    }
};