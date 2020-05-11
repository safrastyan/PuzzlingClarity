int growingPlant(int upSpeed, int downSpeed, int desiredHeight) 
{
    int days = 0;
    int h = 0;
    while(true) {
        ++days;
        h += upSpeed;
        if (h >= desiredHeight) {
            return days;
        }
        h -= downSpeed;
    }
    return -1;
}
