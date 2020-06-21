int rounders(int n) 
{
    int ten = 1;
    while (n > 10) {
        int dig = n % 10;
        n /= 10;
        if (dig >= 5) {
            ++n;
        }
        ten *= 10;
    }
    return n * ten;
}
