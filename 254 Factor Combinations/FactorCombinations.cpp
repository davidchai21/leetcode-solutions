class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int> > res;
        vector<int> t;
        helper(res,t,n);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int> t, int n) {
        int i=t.empty()?2:t.back();
        for (;i<=n/i;i++) {
            if (n%i==0) {
                t.push_back(i);
                t.push_back(n/i);
                res.push_back(t);
                t.pop_back();
                helper(res,t,n/i);
                t.pop_back();
            }
        }
    }
};