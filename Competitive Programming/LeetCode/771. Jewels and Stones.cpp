class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        int s = 0;
        for (int i = 0; i < J.size(); ++i) {
            s += std::count(S.begin(), S.end(), J[i]);
        }
        return s;
    }
};