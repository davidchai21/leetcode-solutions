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
    int longestConsecutive(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
    int helper(TreeNode* root,int& res) {
        if (!root) return 0;
        int left=helper(root->left,res);
        int right=helper(root->right,res);
        int t=1;
        if (left && root->left->val-1==root->val) t=max(t,1+left); 
        if (right && root->right->val-1==root->val) t=max(t,1+right);
        res=max(res,t);
        return t;
    }
};