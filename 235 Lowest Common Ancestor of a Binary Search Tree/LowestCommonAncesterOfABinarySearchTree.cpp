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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=root;
        int a=p->val;
        int b=q->val;
        while ((a-res->val)*(b-res->val)>0)
        {
            if (a>res->val) res=res->right;
            else res=res->left;
        }
        return res;
    }
};