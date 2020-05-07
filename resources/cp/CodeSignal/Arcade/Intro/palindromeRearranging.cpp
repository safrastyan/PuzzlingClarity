bool palindromeRearranging(std::string inputString) 
{
    bool found_odd = false;
    for (int i = 0; i <= 25; ++i) {
        char c = 'a' + i;
        auto count = std::count(inputString.begin(), inputString.end(), c);
        if (count % 2 == 0) {
            continue;
        }

        if (inputString.size() % 2 == 0 || found_odd) {
            return false;
        }
        found_odd = true;
    }
    return true;
}   
