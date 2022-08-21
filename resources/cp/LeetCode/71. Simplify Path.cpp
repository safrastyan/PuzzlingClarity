class Solution {
public:
    std::vector<std::string> split(const std::string& s)
    {
        int pos = 0;
        auto f = s.find('/');
        std::vector<std::string> res;
        while (f != std::string::npos) {
            res.push_back(s.substr(pos, f - pos));
            pos = f + 1;
            f = s.find('/', pos);
            std::cout << res.back() << " ";
        }
        res.push_back(s.substr(pos, f - pos));
        return res;
    }
    string simplifyPath(string path) 
    {
        auto a = split(path);
        std::vector<std::string> res;
        for (auto& name: a) {
            if (name == "." || name.empty()) {
                continue;
            }
            if (name == "..") {
                if (!res.empty()) {
                    res.pop_back();
                }
                continue;
            }
            res.push_back(name);
        }
        std::string ans = "/";
        for (auto& name: res) {
            ans += name;
            ans.push_back('/');
        }
        if (!res.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};