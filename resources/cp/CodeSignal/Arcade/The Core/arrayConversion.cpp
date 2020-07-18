void sum(std::vector<int>& a)
{
    std::vector<int> temp;
    for (int i = 0; i < a.size() / 2; ++i) {
        temp.push_back(a[2 * i] + a[2 * i + 1]);
    }
    a = temp;
}

void prod(std::vector<int>& a)
{
    std::vector<int> temp;
    for (int i = 0; i < a.size() / 2; ++i) {
        temp.push_back(a[2 * i] * a[2 * i + 1]);
    }
    a = temp;
}

int arrayConversion(std::vector<int> inputArray) 
{
    int x = 1;
    while (inputArray.size() != 1) {
        if (x % 2 == 1) {
            sum(inputArray);
        } else {
            prod(inputArray);
        }
        ++x;
    }    
    return inputArray.front();
}
