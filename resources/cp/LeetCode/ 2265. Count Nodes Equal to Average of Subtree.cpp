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

    void calc(TreeNode* node, int& sum, int& count)
    {
        if (node == nullptr) {
            return;
        }
        sum += node->val;
        ++count;
        calc(node->left, sum, count);
        calc(node->right, sum, count);
    }

    void rec(TreeNode* node, int& ans)
    {
        if (node == nullptr) {
            return;
        }
        int s = 0, c = 0;
        calc(node->left, s, c);
        calc(node->right, s, c);
        s += node->val;
        ++c;
        s /= c;
        if (s == node->val) {
            ++ans;
        }
        
        rec(node->left, ans);
        rec(node->right, ans);
    }


    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        rec(root, ans);
        return ans;
    }
};