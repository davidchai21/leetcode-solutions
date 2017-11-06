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
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
    void helper(TreeNode* root, int& res) {
        if (!root) return;
        int l=lenB(root->left,root->val)+lenB(root->right,root->val);
        res=max(res,l);
        helper(root->left,res);
        helper(root->right,res);
    }
    int lenB(TreeNode* root, int val) {
        if (!root || root->val!=val) return 0;
        return 1+max(lenB(root->left,val),lenB(root->right,val));
    }
};