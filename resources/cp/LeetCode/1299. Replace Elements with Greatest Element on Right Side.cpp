class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        std::vector<int> res = arr;
        res[res.size() - 1] = -1;
        
        for (int i = arr.size() - 2; i >= 0; --i) {
            res[i] = std::max(res[i + 1], arr[i + 1]);
        }
        return res;
    }
};