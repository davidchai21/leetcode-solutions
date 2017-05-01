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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* pre=new ListNode(INT_MIN);
        pre->next=head;
        ListNode* res=pre;
        ListNode* cur=head->next;
        ListNode* after;
        ListNode* insert;
        pre=head;
        ListNode* p;
        while (cur!=NULL)
        {
            p=res;
            after=cur->next;
            if (cur->val>=pre->val)
            {
                pre=cur;
                cur=cur->next;
            }
            else
            {
                insert=help(p,cur->val);
                cur->next=insert->next;
                insert->next=cur;
                pre->next=after;
                cur=after;
            }
        }
        return res->next;
    }
    inline ListNode* help(ListNode* p, int n)
    {
        ListNode* base=p;
        while (base->next->val<=n)
        {base=base->next;}
        return base;
    }
};