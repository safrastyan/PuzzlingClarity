std::string longestWord(std::string text) 
{
    text.push_back(' ');
    std::string ans;
    std::string cur;
    for (int i = 0; i < text.size(); ++i) {
        if (std::isalpha(text[i])) {
            cur.push_back(text[i]);
            continue;
        }
        if (ans.size() < cur.size()) {
            ans = cur;
        }
        cur = "";
    }
    return ans;
}
