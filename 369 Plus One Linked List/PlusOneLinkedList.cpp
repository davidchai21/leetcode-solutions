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
    ListNode* plusOne(ListNode* head) {
        ListNode* a=reverse(head);
        ListNode* t=a;
        while (t) {
            if (t->val==9) t->val=0;
            else {t->val+=1; break;}
            if (t->next) t=t->next;
            else {
                if (t->val==0) t->next=new ListNode(1); break;
            }
        }
        return reverse(a);
    }
    ListNode* reverse(ListNode* head) {
        ListNode* pre=NULL;
        ListNode* cur=head;
        while (cur) {
            ListNode* n=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n;
        }
        return pre;
    }
};