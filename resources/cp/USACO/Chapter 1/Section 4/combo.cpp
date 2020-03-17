/*
ID: safrast1
TASK: combo
LANG: C++11          
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <tuple>

using code_t = std::tuple<int, int, int>;

int clip(int x, int n)
{
    if (n == 1) {
        return 1;
    }
    if (x > n) {
        return x % n;
    }
    if (x < 1) {
        return x + n;
    }
    return x;
}
void fill(std::set<code_t>& codes, int n, int a, int b, int c )
{
    for (int i = a - 2; i <= a + 2; ++i) {
        for (int j = b - 2; j <= b + 2; ++j) {
            for (int k = c - 2; k <= c + 2; ++k) {
                codes.insert(std::make_tuple(clip(i, n), clip(j, n), clip(k, n)));
            }
        }
    }
}
int main() 
{
    std::ifstream fin ("combo.in");
    std::ofstream fout ("combo.out");
    int n;
    int a, b, c, d, e, f;
    fin >> n >> a >> b >> c >> d >> e >> f;
    std::set<code_t> s;
    fill(s, n, a, b, c);
    fill(s, n, d, e, f);
    fout << s.size() << std::endl;
    return 0;
}