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
    bool checkEqualTree(TreeNode* root) {
        if (!root) return false;
        int sum=sumtree(root);
        return helper(root,sum);
    }
    bool helper(TreeNode* root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right) return false;
        if (root->left && sum==sumtree(root->left)*2) return true;
        if (root->right && sum==sumtree(root->right)*2) return true;
        return helper(root->left,sum) || helper(root->right,sum);
    }
    int sumtree(TreeNode* root) {
        if (!root) return 0;
        return root->val+sumtree(root->left)+sumtree(root->right);
    }
};