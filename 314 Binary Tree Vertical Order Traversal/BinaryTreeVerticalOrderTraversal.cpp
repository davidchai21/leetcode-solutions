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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        map<int,vector<int> > m;
        queue<pair<TreeNode*,int> > q;
        q.push({root,0});
        while (!q.empty()) {
            int n=q.size();
            for (int i=0;i<n;i++) {
                TreeNode* node=q.front().first;
                int level=q.front().second;
                q.pop();
                m[level].push_back(node->val);
                if (node->left) q.push({node->left,level-1});
                if (node->right) q.push({node->right,level+1});
            }
        }
        for (auto t:m) {
            res.push_back(t.second);
        }
        return res;
    }
};