bool do_reverse(std::string& s)
{
    int ind = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            ind = i;
        }
        if (s[i] == ')') {
            auto sub = s.substr(ind + 1, i - ind - 1);
            std::reverse(sub.begin(), sub.end());
            s = s.substr(0, ind) + sub + s.substr(i + 1, s.size() - i);
            return true;
        }
    }
    return false;
}

std::string reverseInParentheses(std::string inputString) 
{
    while (do_reverse(inputString));
    return inputString;
}
