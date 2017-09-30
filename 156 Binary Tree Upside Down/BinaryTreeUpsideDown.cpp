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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        stack<TreeNode*> s;
        if (!root) return root;
        s.push(root);
        while (s.top()->left) s.push(s.top()->left);
        TreeNode* res=s.top();
        TreeNode* cur=res;
        s.pop();
        while (!s.empty()) {
            TreeNode* t=s.top();
            s.pop();
            cur->right=t;
            cur->left=t->right;
            cur=t;
        }
        cur->left=NULL;
        cur->right=NULL;
        return res;
    }
};