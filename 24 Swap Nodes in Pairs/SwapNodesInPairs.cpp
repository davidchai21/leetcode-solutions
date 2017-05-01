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
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* cur=res;
        while (cur->next && cur->next->next)
        {
            ListNode* t=cur->next;
            cur->next=cur->next->next;
            t->next=cur->next->next;
            cur->next->next=t;
            cur=cur->next->next;
        }
        return res->next;
    }
};