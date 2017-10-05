class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        if (n<k || k<1) return res;
        vector<int> s;
        helper(s,res,k,n,0);
        return res;
    }
    void helper(vector<int>& s, vector<vector<int> >& res, int k, int n, int pos) {
        if (s.size()==k) {
            res.push_back(s);
            return;
        }
        for (int i=pos;i<n;i++) {
            s.push_back(i+1);
            helper(s,res,k,n,i+1);
            s.pop_back();
        }
    }
};