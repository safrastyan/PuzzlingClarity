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
    
    bool rec(TreeNode* n, int cur, int t)
    {
        if (n == nullptr) {
            return false;
        }
        
        cur += n->val;
        if (n->left == nullptr && n->right == nullptr) {
            if (t == cur) {
                return true;
            }
        }
        return rec(n->left, cur, t) || rec(n->right, cur, t);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        return rec(root, 0, targetSum);
    }
};