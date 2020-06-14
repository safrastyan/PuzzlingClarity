std::vector<std::string> fileNaming(std::vector<std::string> names) 
{
    std::set<std::string> a;
    for (int i = 0; i < names.size(); ++i) {
        if (a.find(names[i]) == a.end()) {
            a.insert(names[i]);
            continue;
        }
        for (int j = 1; j <= names.size() + 1; ++j) {
            auto name = names[i] + "(" + std::to_string(j) + ")";
            if (a.find(name) != a.end()) {
                continue;
            }
            names[i] = name;
            a.insert(name);
            break;
        }
    }
    
    return names;
}
