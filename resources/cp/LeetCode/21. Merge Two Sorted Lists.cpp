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
    
    ListNode* vec_to_list(const std::vector<int>& a)
    {
        if (a.empty()) {
            return nullptr;
        }
        ListNode* h = new ListNode(a[0]);
        ListNode* n = h;
        for (int i = 1; i < a.size(); ++i) {
            n->next = new ListNode(a[i]);
            n = n->next;
        }
        return h;
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        auto a = list_to_vec(list1);
        auto b = list_to_vec(list2);
        a.insert(a.end(), b.begin(), b.end());
        std::sort(a.begin(), a.end());
        return vec_to_list(a);
    }
};