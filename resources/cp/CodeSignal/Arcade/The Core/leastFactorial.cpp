int leastFactorial(int n) 
{
    int res = 1;
    for (int i = 1; i <= 100; ++i) {
        res *= i;
        if (res >= n) {
            return res;
        }
    }
    return -1;
}
