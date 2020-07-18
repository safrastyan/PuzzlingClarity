std::string strip_sh(const std::string& s)
{
    std::string res;
    for (auto c: s) {
        if (c != '_') {
            res.push_back(c);
        }
    }
    return res;
}

bool adaNumber(std::string line) 
{
    line = strip_sh(line); 
    if (line.empty()) {
        return false;
    }
    int po = std::count(line.begin(), line.end(), '#');
    
    if (po == 0) {
        for (auto c: line) {
            if (c != '_' && !std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    
    if (po != 2) {
        return false;
    }
    
    if (line.back() != '#') {
        return false;
    }
    if (line[1] != '#' && line[2] != '#') {
        return false;
    }
    int pos = line.find('#'); 
    if (pos + 1 == line.size() - 1) {
        return false;
    }
    
    std::string base_str = line.substr(0, pos);
    
    if (base_str[0] == '0') {
        return false;
    }
    if (line[pos + 1] == '0' && line.size() - pos - 2 != 1) {
        return false;
    }
    
    for (auto c: base_str) {
        if (!std::isdigit(c)) {
            return false;   
        }
    }
    int base = std::stoi(base_str);
    if (base < 2 || base > 16) {
        return false;
    }
    for (int i = pos + 1; i < line.size() - 1; ++i) {
        if (line[i] == '_') {
            continue;
        }
        if (std::isdigit(line[i])) {
            if ((line[i] - '0') >= base) {
                return false;
            }
            continue;
        }
        if (!std::isalpha(line[i])) {
            return false;
        }
        
        char c = std::tolower(line[i]);
        if ( (c - 'a' + 10) >= base) {
            return false;
        }
    }
    return true;
}
