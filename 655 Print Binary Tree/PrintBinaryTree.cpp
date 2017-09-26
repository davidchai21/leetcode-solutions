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
    vector<vector<string>> printTree(TreeNode* root) {
        int d=getDepth(root);
        int width=pow(2,d)-1;
        vector<vector<string> > res(d,vector<string>(width,""));
        helper(res,root,0,width-1,0);
        return res;
    }
    int getDepth(TreeNode* root) {
        if (!root) return 0;
        return 1+max(getDepth(root->left),getDepth(root->right));
    }
    void helper(vector<vector<string> >& res, TreeNode* r, int left, int right, int level) {
        if (!r) return;
        int mid=left+(right-left)/2;
        res[level][mid]=to_string(r->val);
        helper(res,r->left,left,mid-1,level+1);
        helper(res,r->right,mid+1,right,level+1);
    }
};