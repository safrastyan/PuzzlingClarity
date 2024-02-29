class Solution {
public:

std::vector<int> sieve_prime_numbers(int n)
{
    std::vector<char> m(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
        if (m[i] == 0) {
            int j = i + i;
            while (j <= n) {
                m[j] = 1;
                j += i;
            }
        }
    }
    std::vector<int> res;
    for (int i = 2; i <= n; ++i) {
        if (m[i] == 0) {
            res.push_back(i);
        }
    }
    return res;
}
    int countPrimes(int n) {
        auto a = sieve_prime_numbers(n - 1);
        return a.size();
    }
};