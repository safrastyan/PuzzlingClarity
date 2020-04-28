class Solution {
public:
    
    vector<int> get_same(vector<int>& a, int size)
    {
        vector<int> res;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == size) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) 
    {
        vector<vector<int>> res;
        for (int i = 1; i <= groupSizes.size(); ++i) {
            auto people = get_same(groupSizes, i);
            if (people.empty()) {
                continue;
            }
            
            
            for (int j = 0; j < people.size() / i; ++j) {
                vector<int> temp;
                for (int k = 0; k < i; ++k) {
                    temp.push_back(people[j * i + k]);
                }
                res.push_back(temp);
            }
        }
        
        return res;
    }
    
};