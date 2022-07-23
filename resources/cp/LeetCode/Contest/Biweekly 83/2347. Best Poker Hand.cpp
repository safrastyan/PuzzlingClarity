class Solution {
public:
    
    bool flush(const std::vector<std::pair<int, char>>& a)
    {
        for (int i = 0; i < 4; ++i) {
            if (a[i].second != a[i + 1].second) {
                return false;
            }
        }
        return true;
    }
    bool tok(const std::vector<std::pair<int, char>>& a)
    {
        for (int i = 0; i < 3; ++i) {
            if (a[i].first == a[i + 1].first && a[i+1].first == a[i+2].first) {
                return true;
            }
        }
        return false;
    }
    
    bool p(const std::vector<std::pair<int, char>>& a)
    {
        for (int i = 0; i < 4; ++i) {
            if (a[i].first == a[i +1].first) {
                return true;
            }
        }
        return false;
    }
    
    
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        std::vector<std::pair<int, char>> a;
        for (int i = 0; i < 5; ++i) {
            a.push_back(std::make_pair(ranks[i], suits[i]));
        }
        std::sort(a.begin(), a.end());
        if (flush(a)) {
            return "Flush";
        } 
        if (tok(a)) {
            return "Three of a Kind";
        }
        if (p(a)) {
            return "Pair";
        }
        return "High Card";
    }
};