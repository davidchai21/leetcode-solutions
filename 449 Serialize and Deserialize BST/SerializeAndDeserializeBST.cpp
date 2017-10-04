/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream os;
        tos(os,root);
        return os.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data=="") return NULL;
        istringstream ss(data);
        string t;
        ss>>t;
        TreeNode* root=new TreeNode(stoi(t));
        while (ss>>t) {
            tot(root,t);
        }
        return root;
    }
private:
    void tos(ostringstream& os, TreeNode* root) {
        if (!root) return;
        os<<to_string(root->val)<<" ";
        tos(os,root->left);
        tos(os,root->right);
    }
    void tot(TreeNode* root, string a) {
        int t=stoi(a);
        if (root->val>t) {
            if (root->left) {
                tot(root->left,a);
            }
            else {
                root->left=new TreeNode(t);
            }
        }
        else {
            if (root->right) {
                tot(root->right,a);
            }
            else {
                root->right=new TreeNode(t);
            }
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));