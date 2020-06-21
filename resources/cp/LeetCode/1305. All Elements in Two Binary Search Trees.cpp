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
    
    void collect(TreeNode* node, std::vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        collect(node->left, res);
        collect(node->right, res);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        std::vector<int> res;
        collect(root1, res);
        collect(root2, res);
        std::sort(res.begin(), res.end());
        return res;
    }
};