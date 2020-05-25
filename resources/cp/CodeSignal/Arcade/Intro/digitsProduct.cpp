int prod(int n)
{
    int p = 1;
    while (n != 0) {
        p *= n % 10;
        n /= 10;
    }
    return p;
}

int digitsProduct(int product) 
{
    for (int i = 1; i <= 1000000; ++i) {
        if (prod(i) == product) {
            return i;
        }
    }

    return -1;
}
