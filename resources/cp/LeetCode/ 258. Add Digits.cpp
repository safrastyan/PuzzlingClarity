class Solution {
public:

    int vortex(int x)
{
    while(x > 9) {
        int s = 0;
        while (x != 0) {
            s += x % 10;
            x/= 10;
        }
        x = s;
    }
    return x;
}

    int addDigits(int num) {
        return vortex(num);        
    }
};