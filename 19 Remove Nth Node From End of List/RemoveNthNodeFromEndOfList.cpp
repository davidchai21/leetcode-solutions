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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head==NULL || head->next==NULL) return NULL;
        ListNode* cur=head;
        ListNode* rm=head;
        int c=0;
        while (cur->next)
        {
            if (c>=n) rm=rm->next;
            cur=cur->next;
            c++;
        }
        if (rm==head && c<n) return head->next;
        else
        {
            rm->next=rm->next->next;
            return head;
        }
    }
};