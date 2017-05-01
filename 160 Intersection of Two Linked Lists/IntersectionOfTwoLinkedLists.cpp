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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a=headA;
        ListNode* b=headB;
        int l1=0,l2=0;
        while (a)
        {
            l1++;
            a=a->next;
        }
        while (b)
        {
            l2++;
            b=b->next;
        }
        a=headA;
        b=headB;
        while (l1>l2)
        {
            a=a->next;
            l1--;
        }
        while (l2>l1)
        {
            b=b->next;
            l2--;
        }
        while (a!=b)
        {
            a=a->next;
            b=b->next;
        }
        return a;
    }
};