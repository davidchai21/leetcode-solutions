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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (!root) return res;
        vector<int> t;
        helper(root,sum,res,t);
        return res;
    }
    void helper(TreeNode* root, int sum, vector<vector<int> >& res, vector<int>& t) {
        t.push_back(root->val);
        if (sum==root->val && !root->left && !root->right) {
            res.push_back(t);
            t.pop_back();
            return;
        }
        if (root->left) helper(root->left,sum-root->val,res,t);
        if (root->right) helper(root->right,sum-root->val,res,t);
        t.pop_back();
    }
};