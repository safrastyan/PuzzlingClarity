/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  
    
    void fill_g(TreeNode* n, std::unordered_map<int, std::vector<int>>& g)
    {
        TreeNode* l = n->left;
        if (l != nullptr) {
            g[n->val].push_back(l->val);
            g[l->val].push_back(n->val);
            fill_g(n->left, g);
        }
        TreeNode* r = n->right;
        if (r != nullptr) {
            g[n->val].push_back(r->val);
            g[r->val].push_back(n->val);
            fill_g(n->right, g);
        }
    }
    
    
    int amountOfTime(TreeNode* root, int start) {
        int res = 0;
        std::unordered_map<int, std::vector<int>> g;
        fill_g(root, g);
        int ans = 0;
        std::queue<std::pair<int, int>> q;
        std::unordered_set<int> mark;
        mark.insert(start);
        q.push(std::make_pair(start, 0));
        while (!q.empty()) {
            auto node = q.front().first;
            auto dist = q.front().second;
            q.pop();
            ans = std::max(ans, dist);
            for (int i = 0; i < g[node].size(); ++i) {
                int newNode = g[node][i];
                if (mark.find(newNode) == mark.end()) {
                    mark.insert(newNode);
                    q.push(std::make_pair(newNode, dist + 1));
                }
            }
        }
        return ans;
    }
};