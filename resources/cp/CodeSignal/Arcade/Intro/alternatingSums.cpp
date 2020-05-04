std::vector<int> alternatingSums(std::vector<int> a) 
{
    int g1 = 0, g2 = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i % 2 == 0) {
            g2 += a[i];
        } else {
            g1 += a[i];
        }
    }
    return std::vector<int>{g2, g1};
}
