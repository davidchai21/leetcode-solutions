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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k<2 || head==NULL || head->next==NULL) return head;
        ListNode* r=new ListNode(0);
        r->next=head;
        ListNode* cur=r;
        ListNode* tail=r;
        while (1) 
        {
            int c=0;
            tail=cur;
            while (tail && c<k)
            {
                tail=tail->next;
                c++;
            }
            if (c==k && tail){
                c=0;
                reverse(cur,tail);
                while (c<k) {cur=cur->next; c++;}
            }
            else break;
        }
        return r->next;
    }
private:
    void reverse(ListNode* head, ListNode* tail)
    {
        ListNode* pre=NULL;
        ListNode* cur=head->next;
        ListNode* n=head->next->next;
        while (cur!=tail)
        {
            cur->next=pre;
            pre=cur;
            cur=n;
            if (n->next){
            n=n->next;}
        }
        head->next->next=tail->next;
        cur->next=pre;
        head->next=cur;
    }
};