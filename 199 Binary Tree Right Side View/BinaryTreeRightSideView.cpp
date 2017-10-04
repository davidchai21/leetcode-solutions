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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            //TreeNode* node=q.top();
            int n=q.size();
            res.push_back(q.front()->val);
            for (int i=0;i<n;i++) {
                TreeNode* t=q.front();
                q.pop();
                if (t->right) q.push(t->right);
                if (t->left) q.push(t->left);
            }
        }
        return res;
    }
};