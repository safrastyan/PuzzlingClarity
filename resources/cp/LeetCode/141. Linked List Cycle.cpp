/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
        int n = 100000;
        for (int i = 0; i < n; ++i) {
            if (head == nullptr) {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};