class Solution {
public:
    int divide(int dividend, int divisor) {
        auto big = static_cast<long long>(std::numeric_limits<int>::max());
        auto small = static_cast<long long>(std::numeric_limits<int>::min());
        if (divisor == -1) {
            return static_cast<int>(std::min(big, -static_cast<long long>(dividend)));
        }
        long long d = dividend;
        d /= divisor;
        return static_cast<int>(std::max(d, small));
    }
};