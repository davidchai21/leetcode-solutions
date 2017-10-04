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
    TreeNode* str2tree(string s) {
        if (s=="") return NULL;
        return helper(s);
    }
    TreeNode* helper(string s) {
        if (s=="") return NULL;
        int i=0;
        while (s[i]!='(') i++;
        int num=stoi(s.substr(0,i));
        TreeNode* root=new TreeNode(num);
        if (i>=s.size()) return root;
        int j=i+1;
        int c=1;
        while (c) {
            if (s[j]==')') c--;
            else if (s[j]=='(') c++;
            j++;
        }
        root->left=helper(s.substr(i+1,j-i-1));
        if (j<s.size()) {
            root->right=helper(s.substr(j+1,s.size()-j-2));
        }
        return root;
    }
};