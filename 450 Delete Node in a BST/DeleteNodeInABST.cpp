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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;
        if (root->val==key) {
            if (!root->right) {
                return deleteNode(root->left,key);
            }
            else {
                TreeNode* node=root->right;
                while (node->left) node=node->left;
                swap(node->val,root->val);
            }
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }
};