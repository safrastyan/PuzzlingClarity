class Solution {
public:
    int longestValidParentheses(string s) 
    {
        std::stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
                continue;
            }
            st.pop();
            if (st.empty()) {
                st.push(i);
                continue;
            }
            int t = st.top();
            ans = std::max(ans, i - t);
        }
            
        return ans;
    }
};