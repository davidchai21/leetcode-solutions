/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        store(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* t=s.top();
        s.pop();
        if (t->right) store(t->right);
        return t->val;
    }
private:
    stack<TreeNode*> s;
    void store(TreeNode* root) {
        while (root) {
            s.push(root);
            root=root->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */