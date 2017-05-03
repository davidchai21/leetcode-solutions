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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* a=head->next->next;
        ListNode* record=head->next;
        int count=1;
        while (a)
        {
            if (count%2)
            {
                ListNode* p=a;
                a=a->next;
                odd->next=p;
                odd=odd->next;
            }
            else
            {
                ListNode* p=a;
                a=a->next;
                even->next=p;
                even=even->next;
            }
            count++;
        }
        odd->next=record;
        even->next=NULL;
        return head;
    }
};