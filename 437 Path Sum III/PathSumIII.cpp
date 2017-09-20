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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return helper(root, 0, sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
    int helper(TreeNode* root, int sum, int standard)
    {
        if (!root) return 0;
        int cur=sum+root->val;
        return (cur==standard)+helper(root->left,cur,standard)+helper(root->right,cur,standard);
    }
};