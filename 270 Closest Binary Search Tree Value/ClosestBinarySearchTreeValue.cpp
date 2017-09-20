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
    int closestValue(TreeNode* root, double target) {
        int a=root->val;
        if (a==target) return a;
        auto kid=a>target?root->left:root->right;
        if (!kid) return a;
        return abs(a-target)<abs(closestValue(kid,target)-target)?a:closestValue(kid,target);
    }
};