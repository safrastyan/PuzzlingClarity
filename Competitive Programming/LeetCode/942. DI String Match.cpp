class Solution {
public:
    vector<int> diStringMatch(string S) 
    {
        int high = S.size();
        int low = 0;
        std::vector<int> res;
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'I') {
                res.push_back(low);
                ++low;
            }
            if (S[i] == 'D') {
                res.push_back(high);
                --high;
            }
        }
        if (S[S.size() - 1] == 'I') {
            res.push_back(high);
        } else {
            res.push_back(low);
        }
        return res;
    }
};