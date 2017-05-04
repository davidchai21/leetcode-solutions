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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        ListNode* cur=head;
        ListNode* help=cur->next;
        while (slow->next!=NULL && help->next!=NULL)
        {
            cur->next=slow->next;
            slow->next=slow->next->next;
            cur->next->next=help;
            cur=help;
            help=cur->next;
        }
        return;
    }
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* n=NULL;
        while (cur!=NULL)
        {
            n=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n;
        }
        return pre;
    }
};