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
    bool isSymmetric(TreeNode* root) {
        return (!root) || check(root->left,root->right);
    }
    bool check(TreeNode* left, TreeNode* right)
    {
        if (!left && !right) return true;
        if (!left && right || !right && left) return false;
        if (left->val!=right->val) return false;
        return check(left->left,right->right) && check(left->right,right->left);
    }
};