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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > res;
        helper(res,root);
        return res;
    }
    int helper(vector<vector<int> >& a, TreeNode* root)
    {
        if (!root) return 0;
        int l=max(helper(a,root->left),helper(a,root->right))+1;
        if (l>a.size()) a.push_back(vector<int>());
        a[l-1].push_back(root->val);
        return l;
    }
};