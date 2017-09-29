class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res,"",n,0);
        return res;
    }
    void helper(vector<string>& res, string t, int left, int right) {
        if (left==0 && right==0) {
            res.push_back(t);
            return;
        }
        if (right>0) helper(res, t+")", left, right-1);
        if (left>0) helper(res, t+"(", left-1, right+1);
    }
};