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
    vector<int> findMode(TreeNode* root) {
        if (!root) return res;
        int height=1;
        int curv=root->val;
        int curh=0;
        getc(root,height,curv,curh);
        curv=root->val;
        curh=0;
        getv(root,height,curv,curh);
        return res;
    }
    void getc(TreeNode* root, int& h, int& curv, int& curh) {
        if (!root) return;
        getc(root->left,h,curv,curh);
        if (root->val==curv) {
            curh++;
        }
        else {
            curv=root->val;
            curh=1;
        }
        h=max(h,curh);
        getc(root->right,h,curv,curh);
    }
    void getv(TreeNode* root, int h, int& curv, int& curh) {
        if (!root) return;
        getv(root->left,h,curv,curh);
        if (root->val==curv) {
            curh++;
        }
        else {
            curv=root->val;
            curh=1;
        }
        if (curh==h) res.push_back(curv);
        getv(root->right,h,curv,curh);
    }
private:
    vector<int> res;
};