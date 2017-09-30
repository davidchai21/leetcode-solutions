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
    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return res[k-1];
    }
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->left);
        res.push_back(root->val);
        helper(root->right);
    }
private:
    vector<int> res;
};