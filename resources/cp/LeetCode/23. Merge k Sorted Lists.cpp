/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    std::vector<int> list_to_vec(ListNode* n)
    {
        std::vector<int> res;
        while (n != nullptr) {
            res.push_back(n->val);
            n = n->next;
        }
        return res;
    }
    
    ListNode* vec_to_list(const std::vector<int>& v)
    {
        if (v.empty()) {
            return nullptr;
        }
        ListNode* h = new ListNode(v[0]);
        ListNode* n = h;
        for (int i = 1; i < v.size(); ++i) {
            n->next = new ListNode(v[i]);
            n = n->next;
        }
        return h;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty()) {
            return nullptr;
        }
        std::vector<int> a;
        for (auto elem: lists) {
            auto temp = list_to_vec(elem);
            a.insert(a.end(), temp.begin(), temp.end());
        }
        std::sort(a.begin(), a.end());
        return vec_to_list(a);
    }
};