int rangeSum(int a, int b)
{
    return (b * (b + 1)) / 2 - ((a - 1) * a) / 2;    
}

int isSumOfConsecutive2(int n) 
{
    int res = 0;
    for (int i = 1; i <= n - 1; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (rangeSum(i, j) == n) {
                ++res;
            }
        }
    }
    return res;
}

/*
rangeSum(1, n) = 1 + 2 + 3 + .... + n = (n * (n + 1)) / 2
rangeSum(a, b) = a + a + 1 + a + 2 + .... + b - 1 + b = rangeSum(1, b) - rangeSum(1, a - 1)
*/