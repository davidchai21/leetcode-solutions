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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n==0) return res;
        TreeNode* root=new TreeNode(1);
        res.push_back(root);
        int k=2;
        while (k<=n) {
            int m=res.size();
            for (int i=0;i<m;i++) {
                addnode(res[i],k,res);
                TreeNode* p=new TreeNode(k);
                p->left=res[i];
                res[i]=p;
            }
            k++;
        }
        return res;
    }
    void addnode(TreeNode* root, int k, vector<TreeNode*>& res) {
        int d=getdepth(root);
        for (int i=0;i<d;i++) {
            TreeNode* r=copy(root);
            TreeNode* cur=r;
            for (int j=0;j<i;j++) cur=cur->right;
            TreeNode* a=new TreeNode(k);
            a->left=cur->right;
            cur->right=a;
            res.push_back(r);
        }
    }
    TreeNode* copy(TreeNode* root) {
        if (!root) return NULL;
        TreeNode* n=new TreeNode(root->val);
        n->left=copy(root->left);
        n->right=copy(root->right);
        return n;
    }
    int getdepth(TreeNode* root) {
        int d=0;
        if (!root) return 0;
        while (root) {
            root=root->right;
            d++;
        }
        return d;
    }
};