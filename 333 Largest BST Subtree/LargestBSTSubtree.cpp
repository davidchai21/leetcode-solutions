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
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;
        int res=1;
        int tmin=0;
        int tmax=0;
        helper(root,tmin,tmax,res,'l');
        return res;
    }
    int helper(TreeNode* root, int& tmin, int& tmax, int& res, char side) {
        if (!root) {
            tmax=INT_MIN;
            tmin=INT_MAX;
            return 0;
        }
        if (!root->left && !root->right) {
            tmin=root->val;
            tmax=root->val;
            return 1;
        }
        int lmin=0;
        int lmax=0;
        int rmin=0;
        int rmax=0;
        int left=helper(root->left,lmin,lmax,res,'l');
        int right=helper(root->right,rmin,rmax,res,'r');
        if (left==-1 || right==-1 || root->val>=rmin || root->val<=lmax) return -1;
        if (left==0) tmin=root->val;
        else tmin=lmin;
        if (right==0) tmax=root->val;
        else tmax=rmax;
        int v=left+right+1;
        res=max(res,v);
        return v;
    }
};