class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> t;
        sort(nums.begin(),nums.end());
        helper(res,t,nums,0);
        return res;
    }
    void helper(vector<vector<int> >& res, vector<int>& t, vector<int> nums, int pos) {
        res.push_back(t);
        unordered_set<int> s;
        for (int i=pos;i<nums.size();i++) {
            if (s.find(nums[i])==s.end()) {
                t.push_back(nums[i]);
                helper(res,t,nums,i+1);
                t.pop_back();
                s.insert(nums[i]);
            }
        }
    }
};