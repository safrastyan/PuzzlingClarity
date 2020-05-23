bool isMAC48Address(std::string inputString) 
{
    if (inputString.size() != 17) {
        return false;
    }
    for (int i = 0; i < inputString.size(); ++i) {
        if (i % 3 == 0 || i % 3 == 1) {
            if (!std::isdigit(inputString[i]) && !(inputString[i] >= 'A' && inputString[i] <= 'F')) {
                return false;
            }
            continue;
        }
        if (inputString[i] != '-') {
            return false;
        }
    }
    return true;
}
