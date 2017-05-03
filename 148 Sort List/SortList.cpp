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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* n=sortList(slow->next);
        slow->next=NULL;
        return merge(sortList(head),n);
    }
private:
    ListNode* merge(ListNode* a, ListNode* b)
    {
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        while (a!=NULL && b!=NULL)
        {
            if (a->val<b->val)
            {
                cur->next=a;
                a=a->next;
            }
            else
            {
                cur->next=b;
                b=b->next;
            }
            cur=cur->next;
        }
        if (a!=NULL) cur->next=a;
        if (b!=NULL) cur->next=b;
        return res->next;
    }
};