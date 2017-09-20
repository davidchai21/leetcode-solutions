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
    int findSecondMinimumValue(TreeNode* root) {
        if (!root || !root->left) return -1;
        int r=root->val;
        int m=INT_MAX;
        helper(root,r,m);
        return m==INT_MAX?-1:m;
    }
    void helper(TreeNode* root, int k, int& v)
    {
        if (!root->left) return;
        if (root->left->val==k) helper(root->left, k, v);
        else {
            if (root->left->val<v) v=root->left->val;
        }
        if (root->right->val==k) helper(root->right, k, v);
        else {
            if (root->right->val<v) v=root->right->val;
        }
    }
};