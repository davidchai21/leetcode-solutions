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
    ListNode* reverseList(ListNode* head) {
        ListNode* cur=head;
        ListNode* n=NULL;
        ListNode* pre=NULL;
        while (cur)
        {
            n=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n;
        }
        return pre;
    }
};