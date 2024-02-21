class Solution {
public:

    int gcd(int a, int b)
    {
        if (a < b) {
            std::swap(a, b);
        }
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int findGCD(vector<int>& nums) {
        return gcd(*std::max_element(nums.begin(), nums.end()), *std::min_element(nums.begin(), nums.end()));    
    }
};