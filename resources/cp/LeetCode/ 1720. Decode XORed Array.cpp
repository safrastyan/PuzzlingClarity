class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        std::vector<int> res{first};
        for (int i = 0; i < encoded.size(); ++i) {
            res.push_back(res.back() ^ encoded[i]);
        }
        return res;
    }
};