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
    ListNode *detectCycle(ListNode *head) {
        ListNode* a=head;
        ListNode* b=head;
        while (b && b->next)
        {
            a=a->next;
            b=b->next->next;
            if (a==b) break;
        }
        if (b && b->next)
        {
            b=head;
            while (a!=b)
            {
                a=a->next;
                b=b->next;
            }
            return a;
        }
        return NULL;
    }
};