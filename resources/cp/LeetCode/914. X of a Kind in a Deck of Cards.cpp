class Solution {
public:
int gcd(int a, int b)
{
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

    bool hasGroupsSizeX(vector<int>& deck) {
        int a = 0;
        for (auto elem: deck) {
            a = gcd(a, std::count(deck.begin(), deck.end(), elem));
        }
        return a > 1;
    }
};