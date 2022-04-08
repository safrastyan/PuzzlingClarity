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
    
    TreeNode* rec(const std::vector<int>& a, int left, int right)
    {
        if (left > right) {
            return nullptr;
        }
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = rec(a, left, mid - 1);
        root->right = rec(a, mid + 1, right);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       
        return rec(nums, 0, nums.size() - 1);
        
    }
};