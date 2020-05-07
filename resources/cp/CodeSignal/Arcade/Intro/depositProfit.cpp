int depositProfit(int deposit, int rate, int threshold) 
{
    float d = deposit;
    for (int i = 1; i <= 100000; ++i) {
        d *= (100 + rate);
        d /= 100;
        if (d >= threshold) {
            return i;
        }
    }     
    return 0;
}
