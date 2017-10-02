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
    int rob(TreeNode* root) {
        pair<int,int> t=helper(root);
        return max(t.first,t.second);
    }
    pair<int,int> helper(TreeNode* root) {
        if (!root) return make_pair(0,0);
        pair<int,int> left=helper(root->left);
        pair<int,int> right=helper(root->right);
        int a=left.second+right.second;
        int b=max(a,left.first+right.first+root->val);
        return make_pair(a,b);
    }
};