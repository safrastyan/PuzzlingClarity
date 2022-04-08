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
    
    int height(TreeNode* n)
    {
        if (n == nullptr) {
            return 0;
        }
        return std::max(height(n->left), height(n->right)) + 1;
    }
    bool isBalanced(TreeNode* root) 
    {
        if (root == nullptr) {
            return true;
        }
        return std::abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);       
    }
};