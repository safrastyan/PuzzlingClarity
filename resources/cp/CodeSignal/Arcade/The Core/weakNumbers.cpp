std::vector<int> weakNumbers(int n) 
{
    std::vector<int> divs(n + 1);
    std::vector<int> weakness(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        int res = 0;
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) {
                ++res;   
            }
        }
        divs[i] = res;
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            if (divs[j] > divs[i]) {
                ++weakness[i];
            }
        }
    }
    
    auto w = *std::max_element(weakness.begin(), weakness.end());
    auto c = std::count(weakness.begin() + 1, weakness.end(), w);
    return std::vector<int>{w, c};   
}
