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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while (!q.empty()) {
            int n=q.size();
            vector<int> t(n,0);
            for (int i=0;i<n;i++) {
                TreeNode* node=q.front();
                q.pop();
                t[i]=node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (level++%2) reverse(t.begin(),t.end());
            res.push_back(t);
        }
        return res;
    }
};