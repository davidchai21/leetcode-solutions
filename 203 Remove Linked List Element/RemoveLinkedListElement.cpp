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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* r=new ListNode(0);
        r->next=head;
        ListNode* cur=r;
        while (cur && cur->next)
        {
            if (cur->next->val==val)
            {
                cur->next=cur->next->next;
            }
            else cur=cur->next;
        }
        return r->next;
    }
};