class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> t;
        helper(nums,t,0,res);
        return res;
    }
    void helper(vector<int> nums, vector<int>& t, int pos, vector<vector<int> >& res) {
        if (t.size()>1) res.push_back(t);
        unordered_set<int> m;
        for (int i=pos;i<nums.size();i++) {
            if ((t.empty() || nums[i]>=t.back()) && (m.find(nums[i])==m.end())) {
                t.push_back(nums[i]);
                helper(nums,t,i+1,res);
                t.pop_back();
                m.insert(nums[i]);
            }
        }
    }
};