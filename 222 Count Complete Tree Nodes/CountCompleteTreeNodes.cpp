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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int left=0;
        TreeNode* cur=root->left;
        while (cur) {
            left++;
            cur=cur->left;
        }
        int right=0;
        cur=root->right;
        while (cur) {
            right++;
            cur=cur->right;
        }
        if (left==right) return pow(2,left+1)-1;
        else return countNodes(root->left)+countNodes(root->right)+1;
    }
};