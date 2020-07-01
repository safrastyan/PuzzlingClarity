class Solution {
public:
    int arrangeCoins(int n) 
    {
        ////// k^2 + k - 2 *n = 0
        /////  a*x^2 + b*x + c = 0
        double a = 1;
        double b = 1;
        double c = -2 * static_cast<double>(n);
        double D = b * b - 4 * a * c;
        double x = (-b + std::sqrt(D)) / (2 * ad
        return std::floor(x);
    }
};