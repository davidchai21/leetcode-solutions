class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> t;
        int sum=0;
        helper(res,t,candidates,sum,target);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int>& t, vector<int> candidate, int& sum, int target) {
        if (sum==target) {
            res.push_back(t);
            return;
        }
        for (int i=0;i<candidate.size();i++) {
            if (sum+candidate[i]<=target && (t.empty() || candidate[i]>=t.back())) {
                t.push_back(candidate[i]);
                sum+=candidate[i];
                helper(res,t,candidate,sum,target);
                sum-=candidate[i];
                t.pop_back();
            }
        }
    }
};