bool increaseNumberRoundness(int n) 
{
    int seen_non_zero = false;
    while (n != 0) {
        if (n % 10 != 0) {
            seen_non_zero = true;
        }
        if (n % 10 == 0) {
            if (seen_non_zero) {
                return true;
            }
        }
        n /= 10;
    }
    return false;
}
