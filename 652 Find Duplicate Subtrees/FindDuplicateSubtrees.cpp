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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,vector<TreeNode*> > m;
        helper(root,m);
        vector<TreeNode*> res;
        for (auto p:m) {
            if (p.second.size()>1) {
                res.push_back(p.second[0]);
            }
        }
        return res;
    }
    string helper(TreeNode* root, unordered_map<string,vector<TreeNode*> >& m) {
        if (!root) return "NULL";
        string t="("+to_string(root->val)+helper(root->left,m)+helper(root->right,m)+")";
        m[t].push_back(root);
        return t;
    }
};