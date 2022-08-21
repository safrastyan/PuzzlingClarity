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
    
    void rec(TreeNode* n, int lvl, std::vector<std::vector<int>>& a)
    {
        if (n == nullptr) {
            return;
        }
        a[lvl].push_back(n->val);
        rec(n->left, lvl + 1, a);
        rec(n->right, lvl + 1, a);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> a(3000);
        rec(root, 0, a);
        for (int i = 0; i < a.size(); ++i) {
            if (a[i].empty()) {
                a.erase(a.begin() + i, a.end());
                break;
            }
        }
        return a;
    }
};