class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > res;
        if ((19-k)*k/2<n) return res;
        vector<int> t;
        helper(res,t,k,n);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int> t, int k, int n) {
        if (k==0) {
            if (n==0) res.push_back(t);
            return;
        }
        if (n<=0) return;
        int i=t.size()==0?1:(t[t.size()-1]+1);
        for (;i<=9;i++) {
            vector<int> a=t;
            a.push_back(i);
            helper(res,a,k-1,n-i);
        }
    }
};