int sumUpNumbers(std::string inputString) 
{
    int sum = 0;
    int cur = 0;

    inputString.push_back('a');
    for (auto c: inputString) {
        if (std::isdigit(c)) {
            cur *= 10;
            cur += c - '0';
            continue;
        }
        sum += cur;
        cur = 0;
    }
    return sum;
}
