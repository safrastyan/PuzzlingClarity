/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    
    void traverse(TreeNode* node, std::vector<int>& vals)
    {
        if (node == nullptr) {
            return;
        }
        vals.push_back(node->val);
        traverse(node->left, vals);
        traverse(node->right, vals);
    }
    
    void modify(TreeNode* node, std::vector<int>& vals)
    {
        if (node == nullptr) {
            return;
        }
        int sum = 0;
        for (int i = 0; i < vals.size(); ++i) {
            if (node->val <= vals[i]) {
                sum += vals[i];
            }
        }
        node->val = sum;
        modify(node->left, vals);
        modify(node->right, vals);
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        std::vector<int> vals;    
        traverse(root, vals);
        modify(root, vals);
        return root;

    }
};