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
    void rec(TreeNode* n, std::vector<int>& ans)
    {
        if (n == nullptr) {
            return;
        }
        ans.push_back(n->val);
        rec(n->left, ans);
        rec(n->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> res;
        rec(root, res);
        return res;
    }
};