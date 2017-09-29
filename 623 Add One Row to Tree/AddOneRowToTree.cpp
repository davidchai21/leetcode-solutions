/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode* n=new TreeNode(v);
            n->left=root;
            return n;
        }
        queue<TreeNode*> q;
        q.push(root);
        for (int i=2;i<d;i++) {
            int n=q.size();
            for (int j=0;j<n;j++) {
                TreeNode* t=q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        while (!q.empty()) {
            TreeNode* t=q.front();
            q.pop();
            helper(t,v);
        }
        return root;
    }
    void helper(TreeNode* root, int v) {
        if (!root) return;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        root->left=new TreeNode(v);
        root->right=new TreeNode(v);
        root->left->left=left;
        root->right->right=right;
    }
};