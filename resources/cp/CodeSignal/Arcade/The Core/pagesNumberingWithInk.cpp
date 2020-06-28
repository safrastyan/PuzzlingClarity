int digs(int x)
{
    int res = 0;
    while (x != 0) {
        ++res;
        x /= 10;
    }
    return res;
}

int pagesNumberingWithInk(int current, int numberOfDigits) 
{
    int res = 0;
    while (digs(current) <= numberOfDigits) {
        numberOfDigits -= digs(current);
        ++res;
        ++current;
    }
    return current - 1;
}
