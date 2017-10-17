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
        ListNode* a=l1;
        ListNode* b=l2;
        bool flag=false;
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        while (a || b) {
            int t=flag;
            if (a) {
                t+=a->val;
                a=a->next;
            }
            if (b) {
                t+=b->val;
                b=b->next;
            }
            cur->next=new ListNode(t%10);
            cur=cur->next;
            flag=t/10;
        }
        if (flag) cur->next=new ListNode(1);
        return res->next;
    }
};