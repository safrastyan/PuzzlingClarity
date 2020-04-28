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
    
    
    int get_height(TreeNode* root)
    {
        if (!root) {
            return 0;
        } 
        return std::max(get_height(root->left), get_height(root->right)) + 1;
    }
    
    int sum(TreeNode* node, int height, int cur_height)
    {
        if (!node) {
            return 0;
        }
        if (height == cur_height) {
            return node->val;
        }
        return sum(node->left, height, cur_height + 1) + sum(node->right, height, cur_height + 1);
    }

    int deepestLeavesSum(TreeNode* root) 
    {
        auto height = get_height(root);
        return sum(root, height, 1);
    }
};