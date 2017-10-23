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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        res.push_back(root->val);
        stack<int> s;
        checkleft(root->left,res);
        checkright(root->right,s);
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
    bool isleaf(TreeNode* root) {
        return !root->left && !root->right;
    }
    void checkleft(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        if (root->left) {
            checkleft(root->left,res);
            inleft(root->right,res);
        }
        else checkleft(root->right,res);
    }
    void inleft(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (isleaf(root)) res.push_back(root->val);
        else {
            inleft(root->left,res);
            inleft(root->right,res);
        }
    }
    void checkright(TreeNode* root, stack<int>& s) {
        if (!root) return;
        s.push(root->val);
        if (root->right) {
            checkright(root->right,s);
            inright(root->left,s);
        }
        else checkright(root->left,s);
    }
    void inright(TreeNode* root, stack<int>& s) {
        if (!root) return;
        if (isleaf(root)) s.push(root->val);
        else {
            inright(root->right,s);
            inright(root->left,s);
        }
    }
};