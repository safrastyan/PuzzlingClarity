std::vector<int> arrayPreviousLess(std::vector<int> items) 
{
    auto temp = items;
    for (int i = 0; i < items.size(); ++i) {
        int found = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (items[j] < items[i]) {
                found = items[j];
                break;
            }
        }
        temp[i] = found;
    }
    return temp;
}
