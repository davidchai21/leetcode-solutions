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
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
private:
    int sum=0;
    void helper(TreeNode* root)
    {
        if (!root) return;
        if (root->right) helper(root->right);
        root->val=(sum+=root->val);
        if (root->left) helper(root->left);
    }
};