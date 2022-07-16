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
class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* original = head;
        if (head == nullptr || k == 0) {
            return head;
        }
        std::vector<int> res;
        while (head != nullptr) {
            res.push_back(head->val);
            head = head->next;
        }
        k %= res.size();
        if (k == 0) {
            return original;
        }
        ListNode* R = new ListNode(res[res.size() - k]);
        ListNode* temp = R;
        for (int i = res.size() - k + 1; i < res.size(); ++i) {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        for (int i = 0; i < res.size() - k; ++i) {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        return R;
            
    }
};