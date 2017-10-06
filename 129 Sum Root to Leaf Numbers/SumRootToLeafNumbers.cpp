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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res=0;
        helper(root,0,res);
        return res;
    }
    void helper(TreeNode* root, int t, int& res) {
        if (!root->left && !root->right) {
            res+=t*10+root->val;
            return;
        }
        if (root->left) helper(root->left,root->val+t*10,res);
        if (root->right) helper(root->right,root->val+t*10,res);
    }
};