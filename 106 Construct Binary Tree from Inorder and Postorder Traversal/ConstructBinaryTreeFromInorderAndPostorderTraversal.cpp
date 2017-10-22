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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return NULL;
        TreeNode* root=new TreeNode(postorder.back());
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre=NULL;
        TreeNode* n=root;
        int i=inorder.size()-1;
        int j=i-1;
        while (j>=0) {
            if (!s.empty() && s.top()->val==inorder[i]) {
                pre=s.top();
                s.pop();
                i--;
            }
            else if (pre) {
                n=new TreeNode(postorder[j--]);
                pre->left=n;
                pre=NULL;
                s.push(n);
            }
            else {
                n=new TreeNode(postorder[j--]);
                s.top()->right=n;
                s.push(n);
            }
        }
        return root;
    }
};