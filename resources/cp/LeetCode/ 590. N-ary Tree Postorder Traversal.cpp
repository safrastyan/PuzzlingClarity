/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void rec(Node* root, std::vector<int>& ans)
    {
        for (auto n: root->children) {
            if (n == nullptr) {
                continue;
            }
            rec(n, ans);
            ans.push_back(n->val);
        }
    }
    
    vector<int> postorder(Node* root) {
        if (root == nullptr) {
            return {};
        }
        std::vector<int> ans;
        rec(root, ans);
        ans.push_back(root->val);
        return ans;      
    }
};