int magicalWell(int a, int b, int n) 
{
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += a * b;
        ++a;
        ++b;
    }
    return res;
}
