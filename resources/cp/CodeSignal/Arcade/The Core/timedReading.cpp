int timedReading(int maxLength, std::string text) 
{
    int res = 0;
    std::string cur;
    text.push_back(' ');
    for (int i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            cur += text[i];
            continue;
        }
        if (cur.size() > 0 && cur.size() <= maxLength) {
            ++res;
        }
        cur = "";
    }
    
    return res;
}
