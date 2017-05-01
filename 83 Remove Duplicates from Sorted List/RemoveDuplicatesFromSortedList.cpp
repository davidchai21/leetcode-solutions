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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* cur=head;
        ListNode* n=head->next;
        while (n)
        {
            if (n->val==cur->val) n=n->next;
            else {cur->next=n; cur=cur->next;}
        }
        cur->next=n;
        return head;
    }
};