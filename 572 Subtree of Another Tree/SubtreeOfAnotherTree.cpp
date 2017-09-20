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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (!t) return true;
        queue<TreeNode*> q;
        q.push(s);
        while (!q.empty()) {
            TreeNode* node=q.front();
            q.pop();
            if (check(node,t)) return true;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return false;
    }
private:
    bool check(TreeNode* s, TreeNode* t) {
        if (!s && !t) return true;
        if (!s && t || s && !t) return false;
        if (s->val!=t->val) return false;
        return check(s->left,t->left) && check(s->right,t->right);
    }
};