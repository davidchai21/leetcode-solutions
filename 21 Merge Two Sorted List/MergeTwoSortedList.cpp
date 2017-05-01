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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* res=head;
        ListNode* a=l1;
        ListNode* b=l2;
        while (a && b)
        {
            if (a->val<b->val)
            {
                head->next=a;
                a=a->next;
            }
            else
            {
                head->next=b;
                b=b->next;
            }
            head=head->next;
        }
        if (!a) head->next=b;
        else head->next=a;
        return res->next;
    }
};