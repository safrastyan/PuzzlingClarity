bool isMAC48Address(std::string inputString) 
{
    if (inputString.size() != 17) {
        return false;
    }
    
    for (int i = 0; i < inputString.size(); ++i) {
        if (i % 3 == 2) {
            if (inputString[i] != '-') {
                return false;
            }
            continue;
        }
        if (std::isdigit(inputString[i]) || (inputString[i] >= 'A' && inputString[i] <= 'F')) {
            continue;
        }
        return false;
    }
    return true;
}
