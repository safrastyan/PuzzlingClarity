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
    
    int length(ListNode* a)
    {
        int res = 0;
        while (a != nullptr) {
            ++res;
            a = a->next;
        }
        return res;
    }
    
    void carry_if_necessary(ListNode* a)
    {
        while (a != nullptr && a->val >= 10) {
            a->val -= 10;
            if (a->next == nullptr) {
                a->next = new ListNode(0);
            }
            a->next->val += 1;
            a = a->next;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (length(l1) < length(l2)) {
            std::swap(l1, l2);
        }
        
        ListNode* big = l1;
        ListNode* small = l2;
        while (small != nullptr) {
            big->val += small->val;
            carry_if_necessary(big);
            big = big->next;
            small = small->next;
        }
        return l1;
            
    }
};