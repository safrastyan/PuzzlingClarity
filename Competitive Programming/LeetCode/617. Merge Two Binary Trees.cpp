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
    
    void rec(TreeNode* t1, TreeNode* t2)
    {
        t1->val += t2->val;
        
        if (t2->left != nullptr) {
            if (t1->left == nullptr) {
                t1->left = new TreeNode(0);
            }
            rec(t1->left, t2->left);
        }
        
        if (t2->right != nullptr) {
            if (t1->right == nullptr) {
                t1->right = new TreeNode(0);
            }
            rec(t1->right, t2->right);
        }
        
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        
        if (t1 == nullptr) {
            t1 = new TreeNode(0);
        }
        
        if (t2 == nullptr) {
            t2 = new TreeNode(0);
        }
        
        rec(t1, t2);
        return t1;
    }
};