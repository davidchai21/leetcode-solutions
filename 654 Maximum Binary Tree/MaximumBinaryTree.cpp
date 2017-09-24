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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size()==0) return NULL;
        int index=0;
        for (int i=1;i<nums.size();i++) {
            if (nums[i]>nums[index]) index=i;
        }
        vector<int> left(nums.begin(),nums.begin()+index);
        vector<int> right(nums.begin()+index+1,nums.end());
        TreeNode* root=new TreeNode(nums[index]);
        root->left=constructMaximumBinaryTree(left);
        root->right=constructMaximumBinaryTree(right);
        return root;
    }
};