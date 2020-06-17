int digsum(int n)
{
    return n / 10 + n % 10;    
}

int lateRide(int n) 
{
    int minutes = n % 60;
    int hours = n / 60;
    return digsum(minutes) + digsum(hours);   
}
