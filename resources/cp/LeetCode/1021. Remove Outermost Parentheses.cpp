class Solution {
public:
    string removeOuterParentheses(string S) 
    {
        std::vector<bool> mark(S.size(), false);
        std::stack<int> indices;
        indices.push(0);
        for (int i = 1; i < S.size(); ++i) {
            if (S[i] == '(') {
                indices.push(i);
                continue;
            }
            int t = indices.top();
            indices.pop();
            if (indices.empty()) {
                mark[t] = true;
                mark[i] = true;
            }
        }
        std::string res;
        for (int i = 0; i < S.size(); ++i) {
            if (!mark[i]) {
                res.push_back(S[i]);
            }
        }
        return res;
    }
};