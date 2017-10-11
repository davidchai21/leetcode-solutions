/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* head=NULL;
        TreeLinkNode* tail=NULL;
        while (root) {
            if (root->left) {
                if (head==NULL) {
                    head=root->left;
                    tail=head;
                }
                else {
                    tail->next=root->left;
                    tail=tail->next;
                }
            }
            if (root->right) {
                if (head==NULL) {
                    head=root->right;
                    tail=head;
                }
                else {
                    tail->next=root->right;
                    tail=tail->next;
                }
            }
            if (root->next==NULL) {
                root=head;
                head=NULL;
                tail=NULL;
            }
            else root=root->next;
        }
    }
};