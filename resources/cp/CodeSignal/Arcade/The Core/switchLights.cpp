std::vector<int> switchLights(std::vector<int> a) 
{
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] == 0) {
            continue;
        }
        for (int j = i; j >= 0; --j) {
            ++a[j];
            a[j] %= 2;
        }
    }
    return a;
}
