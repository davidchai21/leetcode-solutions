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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> m;
        int c=0;
        if (!root) return res;
        helper(root,m,c);
        for (auto a:m) {
            if (a.second==c) res.push_back(a.first);
        }
        return res;
    }
    int helper(TreeNode* root, unordered_map<int,int>& m, int& c) {
        if (!root) return 0;
        int left=helper(root->left,m,c);
        int right=helper(root->right,m,c);
        int key=left+right+root->val;
        m[key]++;
        if (m[key]>c) c=m[key];
        return key;
    }
};