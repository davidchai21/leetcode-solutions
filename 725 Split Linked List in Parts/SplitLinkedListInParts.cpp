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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res(k);
        int n=getLength(root);
        int r=n%k;
        int d=n/k;
        for (int i=0;i<k;i++,r--) {
            res[i]=root;
            ListNode* cur=root;
            ListNode* pre=NULL;
            for (int j=0;j<d+(r>0);j++) {
                pre=cur;
                cur=cur->next;
            }
            if (pre) pre->next=NULL;
            root=cur;
        }
        return res;
    }
    int getLength(ListNode* root) {
        int n=0;
        while (root) {
            n++;
            root=root->next;
        }
        return n;
    }
};