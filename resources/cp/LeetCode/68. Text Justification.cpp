class Solution {
public:
    
    std::vector<std::vector<std::string>> separate(std::vector<std::string>& words, int m)
    {
        std::vector<std::vector<std::string>> res;
        
        std::vector<std::string> cur;
        int cur_w;
        
        for (auto& s: words) {
            if (cur_w + s.size() + cur.size() <= m) {
                cur.push_back(s);
                cur_w += s.size();
                continue;
            }
            res.push_back(cur);
            cur.clear();
            cur.push_back(s);
            cur_w = s.size();
        }
        if (!cur.empty()) {
            res.push_back(cur);
        }
        return res;
    }
    
    int sum(const std::vector<std::string>& words)
    {
        int s = 0;
        for (auto& line: words) {
            s += line.size();
        }
        return s;
    }
    
    std::string justify(const std::vector<std::string>& words, int m)
    {
        int chars = sum(words);
        int left = m - chars;
        if (words.size() == 1) {
            return words.front() + std::string(left, ' ');
        }
        int pad = left / (words.size() - 1);
        int extra = left - (words.size() - 1) * pad;
        
        std::string res;
        for (int i = 0; i < words.size() - 1; ++i) {
        
            res += words[i];
            if (extra > 0) {
                res.push_back(' ');
                --extra;
            }
            res += std::string(pad, ' ');
        }
     
        std::cout << std::endl << std::endl << res + words.back() << std::endl;
        return res + words.back();
    }
    
    std::string justify_last(const std::vector<std::string>& words, int m)
    {
        int chars = sum(words);
        int left = m - chars;
        std::string res;
        for (auto& w: words) {
            res += w;
            res.push_back(' ');
            --left;
        }
        res.pop_back();
        ++left;
        return res + std::string(left, ' ');
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) 
    {
        auto lines = separate(words, maxWidth);
        std::vector<std::string> res;
        
        for (int i = 0; i < lines.size() - 1; ++i) {
            res.push_back(justify(lines[i], maxWidth));
        }
        res.push_back(justify_last(lines.back(), maxWidth));
        return res;
    }
};