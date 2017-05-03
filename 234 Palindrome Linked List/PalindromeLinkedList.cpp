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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast->next && fast->next->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverse(slow->next);
        fast=slow->next;
        slow=head;
        while (fast)
        {
            if (slow->val!=fast->val) return false;
            slow=slow->next;
            fast=fast->next;
        }
        return true;
    }
private:
    ListNode* reverse(ListNode* head)
    {
        ListNode* pre=NULL;
        ListNode* cur=head;
        ListNode* n=NULL;
        while (cur)
        {
            n=cur->next;
            cur->next=pre;
            pre=cur;
            cur=n;
        }
        return pre;
    }
};