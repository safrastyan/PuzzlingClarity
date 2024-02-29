class Solution {
public:
    int lengthOfLIS(vector<int>& a) {

    int n = a.size();
    int ans = 0;
    std::vector<int> lis(n, 1);
   
   
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    
    return *std::max_element(lis.begin(), lis.end());
    }
};