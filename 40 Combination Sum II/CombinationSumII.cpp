class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        sort(candidates.begin(),candidates.end());
        vector<int> t;
        helper(res,candidates,target,t,0);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int> candidate, int target, vector<int>& t, int pos) {
        if (target==0) {
            res.push_back(t);
            return;
        }
        for (int i=pos;i<candidate.size();i++) {
            if (target<candidate[i]) return;
            if (candidate[i]==candidate[i-1] && i>pos) continue;
            t.push_back(candidate[i]);
            helper(res,candidate,target-candidate[i],t,i+1);
            t.pop_back();
        }
    }
};