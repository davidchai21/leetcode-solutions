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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode(0);
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre=NULL;
        TreeNode* n=root;
        int i=0;
        int j=0;
        while (j<inorder.size()) {
            if (s.top()->val==inorder[j]) {
                pre=s.top();
                s.pop();
                j++;
            }
            else if (pre) {
                n=new TreeNode(preorder[i++]);
                pre->right=n;
                s.push(n);
                pre=NULL;
            }
            else {
                n=new TreeNode(preorder[i++]);
                s.top()->left=n;
                s.push(n);
            }
        }
        return root->left;
    }
};