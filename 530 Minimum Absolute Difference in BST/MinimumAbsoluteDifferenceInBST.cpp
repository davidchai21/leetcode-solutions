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
    int getMinimumDifference(TreeNode* root) {
        collect(root);
        int res=INT_MAX;
        for (int i=0;i<s.size()-1;i++)
        {
            int t=s[i+1]-s[i];
            res=res>t?t:res;
        }
        return res;
    }
private:
    vector<int> s;
    void collect(TreeNode* root)
    {
        if (!root) return;
        if (root->left) collect(root->left);
        s.push_back(root->val);
        if (root->right) collect(root->right);
    }
};