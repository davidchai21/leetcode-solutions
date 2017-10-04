class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n=preorder.size();
        if (n<2) return true;
        stack<int> s;
        int standard=INT_MIN;
        for (int i=0;i<preorder.size();i++) {
            if (standard>preorder[i]) return false;
            if (s.empty() || preorder[i]<s.top()) s.push(preorder[i]);
            else {
                while (!s.empty() && s.top()<preorder[i]) {
                    standard=s.top();
                    s.pop();
                }
                s.push(preorder[i]);
            }
        }
        return true;
    }
};