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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* tail=head;
        int count=1;
        while (tail->next!=NULL)
        {
            count++;
            tail=tail->next;
        }
        int n=count-k%count;
        if (n==0) return head;
        else
        {
            ListNode* pre=NULL;
            ListNode* cur=head;
            while (n)
            {
                pre=cur;
                cur=cur->next;
                n--;
            }
            tail->next=head;
            head=pre->next;
            pre->next=NULL;
        }
        return head;
        
    }
};