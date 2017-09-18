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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if (!root) return res;
        q.push(root);
        while (!q.empty())
        {
            long sum=0;
            int n=q.size();
            for (int i=0;i<n;i++)
            {
                sum+=q.front()->val;
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back((double)sum/n);
        }
        return res;
    }
private:
    queue<TreeNode*> q;
};