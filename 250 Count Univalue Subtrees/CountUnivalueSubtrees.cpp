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
    int countUnivalSubtrees(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
    }
    bool helper(TreeNode* root, int& count) {
        if (!root) return true;
        bool left=helper(root->left,count);
        bool right=helper(root->right,count);
        if (left && right && (root->left==NULL || root->left->val==root->val) && (root->right==NULL || root->right->val==root->val)) {
            count++;
            return true;
        }
        return false;
    }
};