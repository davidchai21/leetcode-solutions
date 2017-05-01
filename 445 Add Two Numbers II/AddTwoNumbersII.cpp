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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r=new ListNode(0);
        ListNode* cur=r;
        bool bit=false;
        ListNode* a=reverse(l1);
        ListNode* b=reverse(l2);
        while (a || b)
        {
            int t=bit;
            if (a) {t+=a->val; a=a->next;}
            if (b) {t+=b->val; b=b->next;}
            cur->next=new ListNode(t%10);
            bit=t/10;
            cur=cur->next;
        }
        if (bit)
        {
            cur->next=new ListNode(1);
            cur=cur->next;
            cur->next=NULL;
        }
        return reverse(r->next);
    }
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* cur=head;
        ListNode* pre=NULL;
        ListNode* after=NULL;
        while (cur)
        {
            after=cur->next;
            cur->next=pre;
            pre=cur;
            cur=after;
        }
        return pre;
    }
};