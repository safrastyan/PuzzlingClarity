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
    int minDepth(TreeNode* root) 
    {
        if (root == nullptr) {
            return 0;
        }
        std::queue<std::pair<TreeNode*, int>> q;
        q.push(std::make_pair(root, 1));
        while (true) {
            TreeNode* node = q.front().first;
            int d = q.front().second;
            q.pop();
            if (node == nullptr) {
                continue;
            }
            if (node->left == nullptr && node->right == nullptr) {
                return d;
            }
            q.push(std::make_pair(node->left, d + 1));
            q.push(std::make_pair(node->right, d + 1));
        }
        return -12;
    }
};