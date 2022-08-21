class Solution {
public:
    
    std::unordered_map<char, int> get_hist(const std::string& s)
    {
        std::unordered_map<char, int> m;
        for (auto c: s) {
            ++m[c];
        }
        return m;
    }
    string minWindow(string s, string t) 
    {
        if (s.size() == 1) {
            return s == t ? s : "";
        }
        auto hist = get_hist(t);
        std::unordered_map<char, int> cur;
        int missing = hist.size();
        int left = 0, right = -1;
        int best_left, best_right;
        best_left = 0;
        best_right = 1000000;
        while (right != s.size() - 1) {
            ++right;
            char c = s[right];
            ++cur[c];
            if (cur[c] == hist[c]) {
                --missing;
                while (missing == 0 && left <= right) {
                    if (right - left < best_right - best_left) {
                        best_left = left;
                        best_right = right;
                    }
                    char c = s[left];
                    --cur[c];
                    ++left;
                    if (cur[c] < hist[c])  {
                        ++missing;
                    }
                }
            }

        }
        
        if (best_right == 1000000) {
            return "";
        }
        std::cout << best_left << " " << best_right;
        return s.substr(best_left, best_right - best_left + 1);
    }
};