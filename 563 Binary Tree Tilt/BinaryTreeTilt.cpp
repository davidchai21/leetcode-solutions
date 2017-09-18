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
    int findTilt(TreeNode* root) {
        treesum(root);
        return ans;
    }
private:
    int treesum(TreeNode* root)
    {
        if (!root) return 0;
        int left=treesum(root->left);
        int right=treesum(root->right);
        ans+=abs(left-right);
        return left+right+root->val;
    }
    int ans=0;
};