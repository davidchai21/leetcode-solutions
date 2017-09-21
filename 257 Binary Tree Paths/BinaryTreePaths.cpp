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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        queue<pair<TreeNode*,string> > q;
        q.push(make_pair(root,to_string(root->val)));
        while (!q.empty())
        {
            TreeNode* node=q.front().first;
            string s=q.front().second;
            q.pop();
            if (!node->left && !node->right) {res.push_back(s); continue;}
            if (node->left) q.push(make_pair(node->left,s+"->"+to_string(node->left->val)));
            if (node->right) q.push(make_pair(node->right,s+"->"+to_string(node->right->val)));
        }
        return res;
    }
};