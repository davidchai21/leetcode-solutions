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
    int widthOfBinaryTree(TreeNode* root) {
        int res=0;
        if (!root) return res;
        queue<pair<TreeNode*,int> > q;
        q.push({root,1});
        while (!q.empty()) {
            int n=q.size();
            int left=INT_MAX;
            int right=INT_MIN;
            for (int i=0;i<n;i++) {
                TreeNode* t=q.front().first;
                int index=q.front().second;
                q.pop();
                left=min(left,index);
                right=max(right,index);
                if (t->left) q.push({t->left,2*index-1});
                if (t->right) q.push({t->right,2*index});
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};