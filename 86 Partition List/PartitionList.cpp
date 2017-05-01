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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* a=new ListNode(0);
        ListNode* b=new ListNode(0);
        ListNode* front=a;
        ListNode* end=b;
        while (head)
        {
            if (head->val<x)
            {
                front->next=head;
                front=front->next;
            }
            else 
            {
                end->next=head;
                end=end->next;
            }
            head=head->next;
        }
        end->next=NULL;
        front->next=b->next;
        return a->next;
    }
};