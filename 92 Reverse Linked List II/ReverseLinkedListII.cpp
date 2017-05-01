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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode* r=new ListNode(0);
        r->next=head;
        ListNode* front=r;
        ListNode* end=r;
        int c=0;
        while (c<n)
        {
            if (c<m-1) {front=front->next;}
            end=end->next;
            c++;
        }
        reverse(front,end);
        return r->next;
    }
private:
    void reverse(ListNode* a, ListNode* b)
    {
        ListNode* pre=b->next;
        ListNode* cur=a->next;
        ListNode* after=cur->next;
        while (cur!=b)
        {
            cur->next=pre;
            pre=cur;
            cur=after;
            after=cur->next;
        }
        cur->next=pre;
        a->next=cur;
    }
};