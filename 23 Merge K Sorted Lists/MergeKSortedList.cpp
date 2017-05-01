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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res=new ListNode(INT_MIN);
        ListNode* r=res;
        if (!lists.size()) return res->next;
        while (1)
        {
            int t=-1;
            int val=INT_MAX;
            for (int i=0;i<lists.size();i++)
            {
                if (lists[i] && val>=lists[i]->val)
                {
                    val=lists[i]->val;
                    t=i;
                }
            }
            if (t!=-1)
            {
                res->next=lists[t];
                res=res->next;
                lists[t]=lists[t]->next;
            }
            else return r->next;
        }
    }
};