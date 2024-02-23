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
    void rec(Node* node, std::vector<int>& res)
    {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val);
        for (auto* new_node : node->children) {
            rec(new_node, res);
        }
    }

    vector<int> preorder(Node* root) {
        std::vector<int> res;
        rec(root, res);
        return res;
    }
};