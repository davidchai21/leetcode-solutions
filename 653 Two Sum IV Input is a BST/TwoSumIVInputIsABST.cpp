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
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        sort(s.begin(),s.end());
        int i=0;
        int j=s.size()-1;
        while (i<j)
        {
            if (s[i]+s[j]<k) i++;
            else if (s[i]+s[j]>k) j--;
            else return true;
        }
        return false;
    }
private:
    vector<int> s;
    void helper(TreeNode* root){
        if (root==NULL) return;
        s.push_back(root->val);
        if (root->left!=NULL) helper(root->left);
        if (root->right!=NULL) helper(root->right);
    }
};