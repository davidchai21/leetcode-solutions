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
        vector<TreeNode*> a,b;
        helper(root,p,a);
        helper(root,q,b);
        TreeNode* res;
        for (int i=0;i<a.size() && i<b.size();i++) {
            if (a[i]==b[i]) res=a[i];
            else break;
        }
        return res;
    }
    bool helper(TreeNode* root, TreeNode* p, vector<TreeNode*>& s) {
        s.push_back(root);
        if (root==p) return true;
        if (root->left && helper(root->left,p,s)) return true;
        if (root->right && helper(root->right,p,s)) return true;
        s.pop_back();
        return false;
    }
};