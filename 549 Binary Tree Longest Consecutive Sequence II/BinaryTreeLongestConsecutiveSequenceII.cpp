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
    int longestConsecutive(TreeNode* root) {
        int res=0;
        helper(root,res);
        return res;
    }
    pair<int,int> helper(TreeNode* root, int& res) {
        if (!root) return make_pair(0,0);
        pair<int,int> left=helper(root->left,res);
        pair<int,int> right=helper(root->right,res);
        pair<int,int> t={1,1};
        if (root->left) {
            if (root->left->val+1==root->val) t.first=max(1+left.first,t.first);
            else if (root->left->val-1==root->val) t.second=max(1+left.second,t.second);
        }
        if (root->right) {
            if (root->right->val+1==root->val) t.first=max(1+right.first,t.first);
            else if (root->right->val-1==root->val) t.second=max(1+right.second,t.second);
        }
        res=max(res,t.first+t.second-1);
        return t;
    }
};