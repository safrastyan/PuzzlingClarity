int sum(int n)
{
    int s = 0;
    while (n != 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int digitDegree(int n) 
{
    int res = 0;
    if (n < 10) {
        return 0;
    }

    while (sum(n) >= 10) {
        n = sum(n);
        ++res;
    }
    return res + 1;
}
