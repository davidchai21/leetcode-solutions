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
    void flatten(TreeNode* root) {
        if (!root) return;
        stack<TreeNode*> s;
        while (root) {
            while (root->left) {
                if (root->right) s.push(root->right);
                root->right=root->left;
                root->left=NULL;
                root=root->right;
            }
            if (root->right) root=root->right;
            else {
                if (s.empty()) return;
                root->right=s.top();
                root=s.top();
                s.pop();
            }
        }
    }
};