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
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n=q.size();
            TreeLinkNode* t;
            for (int i=0;i<n-1;i++) {
                t=q.front();
                q.pop();
                t->next=q.front();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            t=q.front();
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
            q.pop();
        }
    }
};