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
    std::vector<int> to_vec(ListNode* a)
    {
        std::vector<int> v;
        while (a != nullptr) {
            v.push_back(a->val);
            a = a->next;
        }
        return v;
    }
    
    ListNode* vec_to_list(const std::vector<int>& v)
    {
        ListNode* a = new ListNode(v[0]);
        ListNode* head = a;
        for (int i = 1; i < v.size(); ++i) {
            a->next = new ListNode(v[i]);
            a = a->next;
        }
        return head;
    }
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        auto v = to_vec(head);
        if (v.size() == 1) {
            return nullptr;
        }
        v.erase(v.begin() + (v.size() - n));
        return vec_to_list(v);
    }
};