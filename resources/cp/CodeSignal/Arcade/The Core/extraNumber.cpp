int extraNumber(int a, int b, int c) 
{
    if (a == b) {
        return c;
    }
    if (a == c) {
        return b;
    }
    return a;
}
