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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* t=s.top();
            s.pop();
            res.push_back(t->val);
            if (t->left) s.push(t->left);
            if (t->right) s.push(t->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};