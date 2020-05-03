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
    
    void rec(TreeNode* node, int val)
    {
        if (val < node->val) {
            if (!node->left) {
                node->left = new TreeNode(val);
                return;
            }
            rec(node->left, val);
            return;
        }
        if (!node->right) {
            node->right = new TreeNode(val);
            return;
        }
        rec(node->right, val);
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        rec(root, val);
        return root;
    }
};