class Solution {
public:
    int dig_sum(int x)
    {
        int ans = 0;
        while (x != 0){
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }

    int countBalls(int lowLimit, int highLimit) {
        std::vector<int> a(100, 0);
        for (int i = lowLimit; i <= highLimit; ++i) {
            ++a[dig_sum(i)];
        }
        return *max_element(a.begin(), a.end());
    }
};