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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL || head->next==NULL) return head;
        ListNode* p=new ListNode(0);
        ListNode* res=p;
        p->next=head;
        ListNode* cur=head;
        bool flag=false;
        while (cur->next!=NULL)
        {
            if (cur->val==cur->next->val)
            {
                flag=true;
                cur->next=cur->next->next;
            }
            else
            {
                if (flag)
                {
                    p->next=cur->next;
                    cur=p->next;
                    flag=false;
                }
                else
                {
                    p=cur;
                    cur=cur->next;
                }
            }
        }
        if (flag) p->next=NULL;
        return res->next;
    }
};