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
    int getDecimalValue(ListNode* head) 
    {
        int ans = 0;
        std::vector<int> bins;
        while (head != nullptr) {
            bins.push_back(head->val);
            head = head->next;
        }
        
        int two = 1;
        for (int i = bins.size() - 1; i >= 0; --i) {
            ans += two * bins[i];
            two *= 2;
        }
        
        return ans;
    }
};