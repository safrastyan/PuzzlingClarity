/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int val(TreeNode* node)
    {
        return node ? node->val : 0;
    }
    
    int sumEvenGrandparent(TreeNode* root) 
    {
        if (!root) {
            return 0;
        }
        int sum = 0;
        if (root->val % 2 == 0) {
            if (root->left != nullptr) {
                sum += val(root->left->left) + val(root->left->right);    
            }
      
            if (root->right != nullptr) {
                sum += val(root->right->left) + val(root->right->right);    
            }
        }
        return sum + sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
    }
};