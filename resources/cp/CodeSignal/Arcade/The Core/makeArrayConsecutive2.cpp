int makeArrayConsecutive2(std::vector<int> statues) 
{
    int res = 0;
    std::sort(statues.begin(), statues.end());
    for (int i = 0; i < statues.size() - 1; ++i) {
        res += statues[i + 1] - statues[i] - 1;
    }
    return res;
}
